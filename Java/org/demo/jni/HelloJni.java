public class HelloJni {
	public native void displayHello(); //java native method declaration
	
	static {
		System.loadLibrary("HelloJniImp"); // load dynamic link lib
	}

	public static void main(String[] args) {
		HelloJni hj = new HelloJni();
		hj.displayHello();
	}
}

