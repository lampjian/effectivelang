//import javafx.print.Printer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class LocalMethodStackOver {

	public static void main(String[] args) {
		testNativeMethodOutOfMem();
	}

	/*public*/ static void testNativeMethodOutOfMem() {
		// create infinite thread pool in local method
		int j=0;
		while(true) {
			Printer.println(j++);
			ExecutorService executors = Executors.newFixedThreadPool(50);
			int i=0;
			while(i++<10) {
				executors.submit(new Runnable() {
					public void run() {
						System.out.println("Fixed Thread Pool");
					}
				});
			}
		}
	}
}


class Printer {
	/*public*/ static void println(int x) {
		System.out.println("Print :"+x);
	}
}

