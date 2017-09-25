public class Constructor2 {
	public static void main(String[] args) {
		new RoundGlyph(5);
	}
}

class Glyph {

	void draw() {
		System.out.println("Glyph draw()");
	}

	Glyph() {
		System.out.println("Glyph before draw();");
		draw();
		System.out.println("Glyph after draw();");
	}
}

class RoundGlyph extends Glyph {
	private int radius = 1;

	RoundGlyph(int r) {
		radius = r;
		System.out.println("RoundGlyph(),radius:" + radius);
	}

	void draw() {
		System.out.println("RoundGlyph.draw(),radius:" + radius);//此处打印是0，而不是1
	}
}
