public class Jstring {
	public static void main(String[] args) {
		Integer it1 = new Integer(2);
		Integer it2 = 2;
		int it3 = 2;
		System.out.println("it1==it2:"+(it1==it2));
		System.out.println("it1==it3:"+(it1==it3));
		System.out.println("it2==it3:"+(it2==it3));
		String s1 = new String("This is a string.");
		String s2 = "This is a string.";
		System.out.println("s1==s2:"+(s1==s2));
		System.out.println("s1.equals(s2):"+(s1.equals(s2)));
		System.out.println("s2+it3 is:"+s2+it3);
		System.out.println("it3+s2 is:"+it3+s2);
	}
}

