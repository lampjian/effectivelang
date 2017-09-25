public class Demo1 {
	public static void main(String[] args) {  
		Myrthread mt1=new Myrthread("线程a");  
		Myrthread mt2=new Myrthread("线程b");  
		new Thread(mt1).start();  
		new Thread(mt2).start();  
	}  
} 

