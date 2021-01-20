import java.util.Scanner;
public class lab {
	static int gcd(int a, int b) {
		int r = 0;
		for(int i = 1; i <= a; i++) {
			if(a%i == 0 && b%i == 0) r = i;
		}
		return r;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();

		System.out.println(gcd(a, b));
	}
}
