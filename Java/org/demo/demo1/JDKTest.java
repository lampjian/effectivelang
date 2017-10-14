public class JDKTest {
	public static void main(String[] args) {
		ProxyTest pt = new ProxyTest();
		try {
			pt.testProxy();
		} catch (Throwable t) {
			t.printStackTrace();
		}

	}
}
