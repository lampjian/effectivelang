public class JVMStackOutOfMem {

	public static void main(String[] args) {
		testStackOutOfMem();
	}

	private static void testStackOutOfMem() {

		while(true) {
			Thread thread = new Thread(new Runnable() {
				public void run() {
					int i=0;
					while(i<10000) {
						System.out.println("Testing JVM Stack.");
						i++;
					}
				}
			});
			thread.start();
		}
	}
}
