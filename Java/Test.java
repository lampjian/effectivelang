class Mythread extends Thread {
        public void run() {
            //for(int i=0; i<100; i++) {
                System.out.println("Run method");
            //}
            //System.out.println();
        }

}

public class Test {

        public static void main(String[] args) {
                Mythread t1 = new Mythread();
                t1.start();
            //for(int i=0; i<100; i++) {
                System.out.println("Main method");
            //}
        }
}

