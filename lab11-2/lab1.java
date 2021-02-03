//	Recursion version with DP
import java.util.*;
public class lab1 {
	static int[] dp;
	static int solve(int n, int[] coins) {
		if( n == 0 ) return 0;
		if( n < 0 ) return 1000000000;
		if(dp[n] != 0) return dp[n];
		int min = n;
		for(int c : coins) {
			int r = solve(n-c, coins);
			if(r < min) min = r;
		}
		return dp[n] = min+1;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int[] coins = new int[k];
		for(int i = 0; i < k ; i++) {
			coins[i] = scan.nextInt();
		}
		int n = scan.nextInt();
		dp = new int[n+1];
		System.out.println(solve(n, coins));
	}
}
