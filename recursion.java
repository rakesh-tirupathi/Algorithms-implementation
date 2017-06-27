//implementation of recursion

//implementation of factorial using recursion

public class recursion{
	
	public static void factorial(int n){
		if(n==0){
			return 1;
		}
		return n * factorial(n-1);
	}
	
	public static void main(String[] args){
		System.out.println(factorial(5));
	}
}
//---------------------------------------------------------------------
//implementation of towers of hanoi via recursion

public class towersOfHanoi{

	public static void move(int disks, char from, char to, char intermediate){
		if(disks == 1){
			System.out.println("Moving disk " + disks + " from " + from + " to " + to);
		}else{
			move(disks-1, from, intermediate, to);
			System.out.println("Moving disk " + disks + " from " + from + " to " + to);
			move(disks-1, intermediate, to, from);
		}
	}
	
	public static void main(String[] args){
		move(3,'A','C','B');
	}
}