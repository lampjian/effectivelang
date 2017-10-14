package bfs;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by callmedj on 17/8/27.
 */
public class BFSClient {

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        BFSMaster master = ServerSpace.master;

        int blockSize = master.blockSize;
        Printer.println("input\n" +
                "ls to list the file eg: ls /bfs \r\n" +
                "get to get the file eg: get /bfs/some.log \r\n" +
                "put to put a file eg: put 'some' /bfs/some.log \r\n"+
                "delete to delete a file delete /bfs/some.log");
        Printer.println("if you want to exit the command , input :exit");
        while (scanner.hasNext()){
            String command = scanner.nextLine();

            String[] commands = command.split(" ");

            if(commands[0].equals("ls")){
                ClientRequestGetFileBundle requestBundle = new ClientRequestGetFileBundle();
                requestBundle.setFileName(commands[1]);
                Printer.println(master.ls(requestBundle));
            }

            if(commands[0].equals("delete")) {
                ClientRequestGetFileBundle requestBundle = new ClientRequestGetFileBundle();
                requestBundle.setFileName(commands[1]);
                master.delete(requestBundle);
            }

            if(commands[0].equals("put")) {
                String file = commands[1];
                String fileName = commands[2];



                byte[] fileBytes = file.getBytes();

                ClientRequestPutFileBundle requestBundle = new ClientRequestPutFileBundle();
                requestBundle.setFileName(fileName);
                requestBundle.setFileSize(fileBytes.length);

                int fileSpliSize = fileBytes.length / blockSize + 1;

                requestBundle.setFileSplit(fileSpliSize);

                ClientResponseBundle responseBundle= null;
                try {
                    responseBundle = master.put(requestBundle);
                } catch (Exception e) {
                    e.printStackTrace();
                    Printer.println("disk is full");
                    continue;
                }


                List<ChunkToChunkServerPair> pairs = responseBundle.getChunkToServerMap();

                for(int i = 0 ; i < fileSpliSize ; i++){
                    byte[] current = Arrays.copyOfRange(fileBytes,i*blockSize,(i+1)*blockSize);

                    ChunkToChunkServerPair currentPair = pairs.get(i);
                    List<BFSChunkServer> servers = currentPair.getChunkServer();
                    String chunkId = currentPair.getChunkId();
                    for(BFSChunkServer server : servers){
                        try {
                            server.storeChunk(current,chunkId);
                        } catch (Exception e) {
                            e.printStackTrace();
                            ClientRequestGetFileBundle request = new ClientRequestGetFileBundle();
                            requestBundle.setFileName(fileName);
                            master.delete(request);
                            break;
                        }
                    }

                }

                Printer.println("store file"+fileName +" success");
            }

            if(commands[0].equals("get")) {
                String fileName = commands[1];
                ClientRequestGetFileBundle requestBundle = new ClientRequestGetFileBundle();
                requestBundle.setFileName(fileName);

                ClientResponseBundle bundle = master.get(requestBundle);

                List<ChunkToChunkServerPair> pairs = bundle.getChunkToServerMap();

                int chunkSize = pairs.size();
                List<byte[]> fileListWithIndex = new ArrayList<>();
                for(int i = 0 ; i < chunkSize ; i++){
                    ChunkToChunkServerPair current = pairs.get(i);

                    boolean isFind = false;

                    String chunkId = current.getChunkId();
                    List<BFSChunkServer> servers = current.getChunkServer();
                    int serverSize = servers.size();

                    for(int j = 0 ; j<servers.size() && !isFind ; j++){
                        BFSChunkServer currentServer = servers.get(j);
                        byte[] file = currentServer.getChunk(chunkId);

                        if(file == null) continue;
                        else {
                            isFind = true;
                            fileListWithIndex.add(file);
                        }
                    }
                }

                for(byte[] file : fileListWithIndex){
                    System.out.print(new String(file));
                }


                Printer.println("");
            }

            if(command[0].equals(":exit")){
                System.exit(0);
            }

        }

    }
}
