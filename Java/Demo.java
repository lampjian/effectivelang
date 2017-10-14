public class Demo {
	public static void main(String[] args) {
		System.out.println(A.width);
		A a = new A();
		System.out.println(a.width);
		a.test();
	}
}

class A{
	public static int width=100; //静态变量，静态域 field
	private short x;
	static{
		System.out.println("静态初始化类A");
		width = 300 ;
	}
	public A() {
		System.out.println("创建A类的对象");
		x = 20;
	}

	void test() {
		System.out.println("This obj width:"+width);
		System.out.println(width+"-This obj width.");
		String s = width+"Hello";
		String s1 = "Hello"+width;
		x = 300;
		String l = x+"Hello";
		String l1 = "Hello"+x;
		System.out.println("This obj s:"+s);
		System.out.println("This obj l:"+l);
		System.out.println("This obj s1:"+s1);
		System.out.println("This obj l1:"+l1);
		System.out.println("This obj l==s:"+(l==s));
		System.out.println("This obj l1==s1:"+(l1==s1));

		System.out.println("This obj x:"+x);

		String m = "Hello";
		String n = "Hello";
		String m1 = new String("Hello");
		String n1 = new String("Hello");
		System.out.println("This obj m==n:"+(m==n));
		System.out.println("This obj m1==n1:"+(m1==n1));


	}
}
