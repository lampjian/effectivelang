import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ThreadPool {
	public static void main(String[] args) {
		ExecutorService threadPool = Executors.newCachedThreadPool();
		for(int i=0; i<10; i++) {
			final int taskId = i;
			threadPool.execute(new Runnable() {
				public void run() {
					for(int i=1;i<10;i++) {
						System.out.println(Thread.currentThread().getName()+" is looping of "+i+" the task is "+taskId);
						try {
							Thread.sleep(10);
						} catch(InterruptedException e) {
							e.printStackTrace();
						}
					}
				}
			});
		}
		System.out.println("Add all of 10 task.");
		threadPool.shutdown();
		System.out.println("Cached Thread Pool end.");

		ExecutorService threadPool2 = Executors.newFixedThreadPool(3);         
		for(int i=1; i<=10; i++){
			final int taskId = i;
			threadPool2.execute(new Runnable(){
				public void run() {
					for(int i=1; i<=10; i++){
						System.out.println(Thread.currentThread().getName() + " is looping of " + i + " the task is " + taskId);  
						try {
							Thread.sleep(20);
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}
			});
		}
		System.out.println("add  all of 10 task");
		threadPool2.shutdown();
		System.out.println("Fixed Thread Pool end.");
	}
}
