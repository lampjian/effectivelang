public class GeneralReflect {
	public static void main(String[] args) {
		System.out.println(getType().toString());
		System.out.println(new String().getClass().getName());
	}

	private static Class<String> getType() {
		return String.class;
	}
}
