package bfs;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by callmedj on 17/8/27.
 */
public class ClientResponseBundle {

    private List<ChunkToChunkServerPair> chunkToServerMap = new ArrayList<>();


    public List<ChunkToChunkServerPair> getChunkToServerMap() {
        return chunkToServerMap;
    }

    public void setChunkToServerMap(List<ChunkToChunkServerPair> chunkToServerMap) {
        this.chunkToServerMap = chunkToServerMap;
    }


}
