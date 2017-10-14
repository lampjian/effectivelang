class test {
	public static void main(String []args) {
		System.out.println("Main");
		String s = "Hello";
		String t = "Hello";
		String r = "World";
		String i = t +' '+r;
		String x = "Hello World";
		System.out.println("s==t:"+(s==t)+",t==r:"+(t==r)+",i==x:"+(i.equals(x))+",i:"+i);
		String test = new String("Test");
		String tes = "Test";
		System.out.println("test==tes?"+(test.equals(tes)));

	}
}
