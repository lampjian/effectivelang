public class Init2{

	// initialization executed once per class
	static{
		System.out.println("Initialization Mainclass");
	}

	public static void main(String[] args){
		/*
		System.out.println(Sub.y);
		System.out.println("Final statics:end.");
		System.out.println(Sub.x);
		System.out.println("Super statics:end.");
		*/
		System.out.println(Sub.z);
		System.out.println("Sub uninit statics:end.");
	}
}
