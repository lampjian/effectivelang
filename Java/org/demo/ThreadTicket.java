public class ThreadTicket {
	public static void main(String[] args) {
		Myth mt1=new Myth();
		Myth mt2=new Myth();
		Myth mt3=new Myth();
		mt1.start();//每个线程都各卖了10张，共卖了30张票
		mt2.start();//但实际只有10张票，每个线程都卖自己的票
		mt3.start();//没有达到资源共享
	}
}
