public class Multiple {
	public static void main(String[] args) {

		Bill b = null;
		PhoneBill pb = new PhoneBill();
		GasBill gb = new GasBill();
		Multiple mt = new Multiple();
		mt.calculate(b);
		b = gb;
		mt.calculate(b);
		mt.calculate(pb);
		mt.calculate(gb);
	}

	public double calculate(Bill bill) {
		if(bill == null)
			System.out.println("bill is null");
		if(bill instanceof PhoneBill) {
			System.out.println("calPhonebill");
		}
		if(bill instanceof GasBill) {
			System.out.println("calGasbill");
		}
		if(bill instanceof Bill) {
			System.out.println("calBill");
		}
		return 0;
	}
}

class Bill {
	Bill(){
		System.out.println("Bill here.");
	}
}

class PhoneBill extends Bill {
	PhoneBill() {
		System.out.println("Phone Bill here.");
	}
}

class GasBill extends Bill {
	GasBill() {
		System.out.println("Gas Bill here.");
	}
}

