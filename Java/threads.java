class Mythread extends Thread {
	public void run() {
		System.out.println("Run method");
	}

}

public class Test { 

	public static void main(String[] args) {
		Mythread t1 = new Mythread();
		t1.start()
		System.out.println("Main method");
	}
}

