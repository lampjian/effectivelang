class Hello2 {
	private void displayHello() {
		System.out.println("Hello test.");
	}

	static {
		System.out.println("Hello Imp"); // load dynamic link lib
	}

	public static void main(String[] args) {
		Hello2 h2 = new Hello2();
		h2.displayHello();
	}
}

