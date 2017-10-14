package bfs;

/**
 * Created by callmedj on 17/8/27.
 */
public class ServerSpace {
    public static final BFSMaster master = new BFSMaster();

    public static final BFSChunkServer server1 = new BFSChunkServer(100,0,"/","192.168.1.101");
    public static final BFSChunkServer server2 = new BFSChunkServer(100,0,"/","192.168.1.102");
    public static final BFSChunkServer server3 = new BFSChunkServer(100,0,"/","192.168.1.103");
    public static final BFSChunkServer server4 = new BFSChunkServer(100,0,"/","192.168.1.104");
    public static final BFSChunkServer server5 = new BFSChunkServer(100,0,"/","192.168.1.105");
    public static final BFSChunkServer server6 = new BFSChunkServer(100,0,"/","192.168.1.106");


    static{
        master.registerChunkServer(server1);
        master.registerChunkServer(server2);
        master.registerChunkServer(server3);
        master.registerChunkServer(server4);
        master.registerChunkServer(server5);
        master.registerChunkServer(server6);

        master.gc();
    }
}
