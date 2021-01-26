import java.util.Scanner;
public class lab {
	public static long fib(int n) {
		if(n <= 1) return n;
		long f1=1, f2=0, fn = n;
		for(int i = 2; i <= n; i++) {
			fn = (f1+f2)%1000000009;
			f2 = f1;
			f1 = fn;
		}
		return fn;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(n+" : "+fib(n));
	}
}
