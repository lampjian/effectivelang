class Myth implements Runnable{
	private int ticket=10;
	public void run(){
		for(int i=0;i<20;i++){
			if(this.ticket>0){
				System.out.print(this.toString()+" ->");
				System.out.println("卖票：ticket"+this.ticket--);
			}
		}
	}
}
