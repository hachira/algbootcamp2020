import java.util.Scanner;
public class lab {
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
		int n = scan.nextInt();
		int a = scan.nextInt();
		int b = scan.nextInt();
		long c = a/gcd(a, b)*b;
		int na = n/a;
		int nb = n/b;
		int nc = (int)(n/c);
		long sum = (long)a*na*(na+1)/2+ (long)b*nb*(nb+1)/2- c*nc*(nc+1)/2;
		System.out.println(sum);
	}
}
