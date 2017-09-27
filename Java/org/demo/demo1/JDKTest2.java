public class JDKTest2 {
	public static void main(String[] args) {
		ProxyTest2 pt = new ProxyTest2();
		try {
			pt.testProxy2();
		} catch (Throwable t) {
			t.printStackTrace();
		}
		pt.testGenerateProxyClass();

	}
}
