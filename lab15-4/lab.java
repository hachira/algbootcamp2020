import java.util.*;
public class lab {
	static int phi(int n) {
		int phi = 1;
		if(n%2 == 0) {
			n /= 2;
			while(n%2 == 0) { n/=2; phi*=2; }
		}
		for(int p = 3; p*p <= n; p += 2) {
			if(n%p != 0) continue;
			n /= p;
			phi *= p-1;
			while(n%p == 0) { n/=p; phi*=p; }
		}
		if(n > 1) return (n-1)*phi;
		return phi;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(phi(n));
	}
}
