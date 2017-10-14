public class ThreadTicket {
	public static void main(String[] args) {
		Myth mt=new Myth();
		new Thread(mt).start();//每个线程都各卖了10张，共卖了30张票
		new Thread(mt).start();//但实际只有10张票，每个线程都卖自己的票
		new Thread(mt).start();//没有达到资源共享
	}
}
