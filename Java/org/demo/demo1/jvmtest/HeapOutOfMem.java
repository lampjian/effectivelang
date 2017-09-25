import java.util.List;
import java.util.ArrayList;

public class HeapOutOfMem {

	public static void main(String[] args) {
		testOutOfHeapMem();
	}

	private static void testOutOfHeapMem() {
		// create string buffer object in heap by dead loop
		List<StringBuffer> list = new ArrayList<StringBuffer>();
		while(true) {
			StringBuffer s = new StringBuffer();
			for(int i=0; i<10000; i++) {
				s.append(i);
			}
			list.add(s);
		}
	}
}
