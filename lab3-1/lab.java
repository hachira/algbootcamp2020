import java.util.Scanner;
public class lab {
	static int hanoi(int n) {
		if(n==1) return 1;
		return 2*hanoi(n-1)+1;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(hanoi(n));
	}
}
