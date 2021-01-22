import java.util.Scanner;
public class lab {
	static int fib(int n) {
		int[] v = new int[n+1];
		v[0] = 0;
		v[1] = 1;
		for(int i = 2; i <= n; i++)
			v[i] = v[i-1]+v[i-2];
		return v[n];
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(fib(n));
	}
}
