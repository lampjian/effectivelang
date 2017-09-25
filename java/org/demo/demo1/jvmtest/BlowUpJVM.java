public class BlowUpJVM {


	public static void main(String[] args) {
		testStackOverFlow();
	}

	public static void testStackOverFlow() {
		BlowUpJVM.testStackOverFlow();
	}
}
