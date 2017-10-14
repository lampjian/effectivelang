import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class Schedule {

	public static void main(String[] args) {
		Executors.newScheduledThreadPool(3).scheduleAtFixedRate(
				new Runnable(){
					public void run() {
						System.out.println("boming");
					}
				}, 5, 1, TimeUnit.SECONDS);
	}
}
