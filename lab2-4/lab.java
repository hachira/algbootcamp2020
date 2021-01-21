import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();

		long s1 = 1;
		if(n%2==0) {
			long s = 1;
			while(n%2==0) {
				n /= 2;
				s = s*2 + 1;
			}
			s1 *= s;
		}
		for(int p=3; p*p <= n; p+=2) {
			if(n%p != 0) continue;
			long s = 1;
			while(n%p==0) {
				n /= p;
				s = s*p + 1;
			}
			s1 *= s;
		}
		if(n>1) s1 *= n+1;

		System.out.println(s1);
	}
}

