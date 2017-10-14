package bfs;

import java.util.List;

/**
 * Created by callmedj on 17/9/8.
 */
public     class ChunkToChunkServerPair {
    private  String chunkId;
    private List<BFSChunkServer> chunkServer;

    public String getChunkId() {
        return chunkId;
    }

    public ChunkToChunkServerPair setChunkId(String chunkId) {
        this.chunkId = chunkId;
        return this;
    }

    public List<BFSChunkServer> getChunkServer() {
        return chunkServer;
    }

    public ChunkToChunkServerPair setChunkServer(List<BFSChunkServer> chunkServer) {
        this.chunkServer = chunkServer;
        return this;
    }

}
