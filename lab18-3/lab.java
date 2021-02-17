import java.util.*;
public class lab {
	static long MOD = 1000000007;
	static int gcd(int a, int b) {
		while(b > 0) {
			int t = a%b;
			a = b;
			b = t;
		}
		return a;
	}
	static long[] mul(long[] a, long[] b) {
		long[] c = new long[4];
		c[0] = (a[0]*b[0] + a[1]*b[2])%MOD;
		c[1] = (a[0]*b[1] + a[1]*b[3])%MOD;
		c[2] = (a[2]*b[0] + a[3]*b[2])%MOD;
		c[3] = (a[2]*b[1] + a[3]*b[3])%MOD;
		return c;
	}
	static int fib(int n) {
		long[] a = { 1, 1, 1, 0 }, b = { 1, 0, 0, 1 };
		while(n > 0) {
			if((n&1) != 0) {
				b = mul(a, b);
			}
			a = mul(a, a);
			n >>= 1;
		}
		return (int)b[2];
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int g = gcd(a, b);
		System.out.println(fib(g));
	}
}
