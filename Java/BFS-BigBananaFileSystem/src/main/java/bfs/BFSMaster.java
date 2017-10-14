package bfs;

import java.util.*;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

/**
 * Created by callmedj on 17/8/27.
 */
public class BFSMaster {

    public static int copySize = 3;
    public static int blockSize = 5;//byte
    public List<ChunkLog> logList = new ArrayList<ChunkLog>();
    public List<BFSChunkServer> servers = new ArrayList<>();

    public Map<String,List<String>> fileChunkMap = new HashMap<>();

    public Map<String,List<BFSChunkServer>> chunkServerMap = new HashMap<>();

    public List<String> namespace = new ArrayList<>();

    private BFSMaster self;

    public BFSMaster(){
        self = this;
    }

    public String ls(ClientRequestGetFileBundle request){
        this.log("ls "+request.getFileName());


        String filePath = request.getFileName();

        int filePathLength = filePath.length();
        Set<String> fileSet = new HashSet<>();
        for(String file : namespace){
            int fileIndex = file.indexOf(filePath);
            if(fileIndex == 0 && !file.endsWith(".delete")){


                String menuList = filePathLength == 1 ? file.substring(filePathLength) : file.substring(filePathLength+1);

                int menuIndex = menuList.indexOf('/');

                if(menuIndex != -1){
                    menuList = menuList.substring(0,menuIndex);
                }
                fileSet.add(menuList);
            }
        }

        StringBuilder result = new StringBuilder();

        for(String file : fileSet){
            result.append(file+"\r\n");
        }

        return result.toString();
    }

    private void log(String handle){
        ChunkLog chunkLog = new ChunkLog(handle);
        this.logList.add(chunkLog);
        Printer.println(chunkLog.date +","+chunkLog.handle);
    }

    public ClientResponseBundle get(ClientRequestGetFileBundle request){
        this.log("get "+request.getFileName());
        ClientResponseBundle response = new ClientResponseBundle();
        String file = request.getFileName();

        List<String> chunks = this.fileChunkMap.get(file);

        if(chunks.isEmpty()) return response;

        List<ChunkToChunkServerPair> pairs = new ArrayList<>();
        for(String chunk : chunks){
            pairs.add(new ChunkToChunkServerPair().setChunkId(chunk).setChunkServer(this.chunkServerMap.get(chunk)));
        }

        response.setChunkToServerMap(pairs);
        return response;
    }



    public ClientResponseBundle put(ClientRequestPutFileBundle request) throws Exception {
        this.log("put "+request.getFileName());

        String file = request.getFileName();
        int fileSize = request.getFileSize();
        int fileSplit = request.getFileSplit();


        ClientResponseBundle response = new ClientResponseBundle();

        List<ChunkToChunkServerPair> pairs = new ArrayList<>();


        this.namespace.add(file);
        List<String> chunkList = new ArrayList<>();
        for(int i = 0 ; i < fileSplit; i++) {
            String chunkId = UUID.randomUUID().toString();
            chunkList.add(chunkId);
        }

        this.fileChunkMap.put(file,chunkList);

        //Printer.println("adding map from file to chunkId");
        for(String chunkId : chunkList){
            List<BFSChunkServer> chunkServers = getActiveServer();
            pairs.add(new ChunkToChunkServerPair().setChunkId(chunkId).setChunkServer(chunkServers));
            this.chunkServerMap.put(chunkId,chunkServers);
        }

        response.setChunkToServerMap(pairs);

        for(ChunkToChunkServerPair pair : pairs){
            List<BFSChunkServer> chunkServers = pair.getChunkServer();
            for(BFSChunkServer current : chunkServers){
                current.getServerState().setOccupiedSpace(0);
            }
        }

        // Printer.println("adding map from chunkId to servers");
        return response;
    }

    private double factor = 0.9;
    private List<BFSChunkServer>  getActiveServer() throws Exception {
        List<BFSChunkServer> chunkServers = new ArrayList<>();
        Collections.sort(this.servers, new Comparator<BFSChunkServer>() {
            @Override
            public int compare(BFSChunkServer o1, BFSChunkServer o2) {
                ServerState o1ServerState = o1.getServerState();
                ServerState o2ServerState = o2.getServerState();
                double o1Percentage = Double.valueOf(o1ServerState.getUsedSpace()+o1ServerState.getOccupiedSpace())/Double.valueOf(o1ServerState.getTotalSpace());
                double o2Percentage = Double.valueOf(o2ServerState.getUsedSpace()+o2ServerState.getOccupiedSpace())/Double.valueOf(o2ServerState.getTotalSpace());

                return o1Percentage==o2Percentage?0:(o1Percentage<o2Percentage?-1:1);
            }
        });
        Printer.println(this.servers.toString());

        int serverCount = 0;
        for(BFSChunkServer chunkServer : this.servers){
            if(serverCount >= copySize)
                break;

            ServerState serverState = chunkServer.getServerState();
            int percentage = serverState.getUsedSpace()/serverState.getTotalSpace();

            if (percentage >= factor)
                continue;

            chunkServer.occupiedSpace = serverState.getOccupiedSpace()+blockSize;
            chunkServers.add(chunkServer);
            serverCount++;
        }
        if (serverCount!=copySize){
            throw new Exception("server not enough");
        }


        return chunkServers;

    }


    public void gc(){
        Runnable gc = new Runnable() {
            @Override
            public void run() {
                try {
                    Set<String> fileToGC = new HashSet<>();

                    for (String file : self.namespace) {
                        if (file.endsWith(".delete")) {
                            fileToGC.add(file);
                        }
                    }

                    Set<String> chunkIdsToGC = new HashSet<>();

                    for (String file : fileToGC) {
                        List<String> chunkIds = self.fileChunkMap.get(file);
                        for (String currentChunk : chunkIds) {
                            chunkIdsToGC.add(currentChunk);
                            List<BFSChunkServer> chunkServers = self.chunkServerMap.get(currentChunk);
                            for (BFSChunkServer currentServer : chunkServers) {
                                currentServer.deletChunk(currentChunk);
                            }
                        }
                    }

                    for(String file : fileToGC){
                        self.namespace.remove(file);
                        self.fileChunkMap.remove(file);
                    }
                    for(String chunk : chunkIdsToGC){
                        self.chunkServerMap.remove(chunk);
                    }


                    if(!fileToGC.isEmpty()) {
                        Printer.println("gc complete delete files -> " + fileToGC.toString());
                    }
                }
                catch (Exception e){
                    e.printStackTrace();
                }
            }
        };
        ScheduledExecutorService scheduledExecutorService = Executors.newSingleThreadScheduledExecutor();
        scheduledExecutorService.scheduleAtFixedRate(gc,0,3,TimeUnit.SECONDS);
    }

    public ClientResponseBundle delete(ClientRequestGetFileBundle request){

        this.log("delete "+request.getFileName());
        ClientResponseBundle response = new ClientResponseBundle();
        String file = request.getFileName();

        namespace.remove(file);
        namespace.add(file+".delete");

        List<String> chunks = this.fileChunkMap.get(file);

        this.fileChunkMap.remove(file);

        this.fileChunkMap.put(file + ".delete",chunks);

        return response;
    }



    public void registerChunkServer(BFSChunkServer chunkServer){
        this.servers.add(chunkServer);
    }


}
