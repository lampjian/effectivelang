public class Jstart {  
	public static void main(String[] args) {  
		MyThread mt1=new MyThread("线程x");  
		MyThread mt2=new MyThread("线程y");  
		mt1.start();  
		mt2.start();  
	}  
} 
