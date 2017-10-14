package bfs;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by callmedj on 17/8/27.
 */
public class BFSChunkServer {
    public int totalSpace;
    public int usedSpace;
    public String fileSpace;
    public String ip;
    public int occupiedSpace;

    @Override
    public String toString(){
    return "server "+ip+" ',totalSpace is "+totalSpace+" ,usedSpace is"+usedSpace;
    }

    public Map<String,BFSChunk> chunks = new HashMap<>();

    public BFSChunkServer(int totalSpace,int usedSpace,String fileSpace,String ip){
        this.totalSpace = totalSpace;
        this.usedSpace = usedSpace;
        this.fileSpace = fileSpace;
        this.ip = ip;
    }


    public boolean isActive(){
        return (this.usedSpace/this.totalSpace) <= 0.9D;
    }

    public void storeChunk(byte[] file , String chunkId) throws Exception {

        BFSChunk chunk = new BFSChunk();
        chunk.chunkId = chunkId;
        chunk.file = file;
        int chunkByte = chunk.file.length;
        if(this.usedSpace + chunkByte > totalSpace){
            throw new Exception("disk is full");
        }
        this.usedSpace += chunkByte;

        this.chunks.put(chunkId,chunk);
        Printer.println(" store file "+chunkId+" in " +this.ip + " success! and totalSpace is "+ totalSpace +" ,usedSpace is "+usedSpace+" byte");
    }

    public byte[] getChunk(String chunkId){
        BFSChunk chunk =  chunks.get(chunkId);
        if(chunk == null) return null;
        return chunk.file;
    }

    public ServerState getServerState(){
        return new ServerState(this.isActive(),this.totalSpace,this.usedSpace,this.occupiedSpace);
    }


    public void deletChunk(String chunkId){
        if(this.chunks.containsKey(chunkId)) {
            BFSChunk chunk = chunks.get(chunkId);
            int chunkByte = chunk.file.length;
            this.usedSpace -= chunkByte;
            this.chunks.remove(chunkId);
            Printer.println(this.ip + " delete file "+chunkId+" success! and totalSpace is "+ totalSpace +" ,usedSpace is "+usedSpace+" byte");

        }
    }

}
