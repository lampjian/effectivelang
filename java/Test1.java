class Mythread1 extends Thread {
        public void run() {
			for(int i=0; i<100; i++) {
                System.out.println("Run method");
            }
            System.out.println();
        }

}

public class Test1 {

        public static void main(String[] args) {
                Mythread1 t1 = new Mythread1();
                t1.start();
            for(int i=0; i<100; i++) {
                System.out.println("Main method");
            }
        }
}

