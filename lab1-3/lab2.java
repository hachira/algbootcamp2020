import java.util.Scanner;
public class lab2 {
	static int gcd(int a, int b) {
		while(b != 0) {
			int t = a%b;
			a = b;
			b = t;
		}
		return a;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();

		System.out.println(gcd(a, b));
	}
}
