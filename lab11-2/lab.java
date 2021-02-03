//	Recursion version
import java.util.*;
public class lab {
	static int solve(int n, int[] coins) {
		if( n == 0 ) return 0;
		if( n < 0 ) return 1000000000;
		int min = n;
		for(int c : coins) {
			int r = solve(n-c, coins);
			if(r < min) min = r;
		}
		return min+1;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int[] coins = new int[k];
		for(int i = 0; i < k ; i++) {
			coins[i] = scan.nextInt();
		}
		int n = scan.nextInt();
		System.out.println(solve(n, coins));
	}
}
