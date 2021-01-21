import java.util.Scanner;

public class lab {
	static int pi(int n) {
		if(n < 2) return 0;
		if(n == 2) return 1;

		int start = 3, pn = 1;
		if( n >= 50000000 ) {
			start = 50000001;
			pn = 3001134;
		}
		else if( n >= 10000000 ) {
			start = 10000001;
			pn = 664579;
		}
		for(int p = start; p <= n; p+=2) {
			boolean isPrime = true;
			for(int i = 3; i*i <= p; i+=2) {
				if(p%i==0) {
					isPrime = false;
					break;
				}
			}
			if(isPrime) pn++;
		}
		return pn;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(pi(n));
	}
}
