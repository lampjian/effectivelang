/*
优点：
-避免点继承的局限，一个类可以继承多个接口
-适合于资源的共享
*/

class Myrthread implements Runnable{  
	private String name;  
	public Myrthread(String name) {  
		this.name = name;  
	}
	public void run(){  
		for(int i=0;i<100;i++){  
			System.out.println("线程开始："+this.name+",i="+i);  
		}  
	}  
}
