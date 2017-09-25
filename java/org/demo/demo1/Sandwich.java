class Meal {
	Meal() {
		System.out.println("meal");
	}
}

class Bread {
	Bread() {
		System.out.println("Bread");
	}
}

class Cheese {
	Cheese() {
		System.out.println("Cheese");
	}
	static void eatCheese() {
		System.out.println("Eating Cheese.");
	}
}

class Lettuce {
	Lettuce() {
		System.out.println("Lettuce");
	}
}

class Lunch extends Meal{
	Lunch() {
		System.out.println("Lunch");
	}
}

class PortableLunch extends Lunch{
	PortableLunch() {
		System.out.println("Portable Lunch");
	}
}

public class Sandwich extends PortableLunch {
	public Sandwich() {
		System.out.println("Sandwich");
	}

	private Bread b = new Bread();
	private Cheese c = new Cheese();
	private Lettuce l = new Lettuce();

	public static void main(String[] args) {
		new Sandwich();
		Cheese ce = new Cheese();
		ce.eatCheese();
	}
}
