import java.util.*;
public class lab {
	static int[][] dp;
	static int[][] table;
	static int[] pattern = { 1, 2, 4, 5 };

	static int pebbleSum(int col, int pat) {
		int sum = 0;
		for(int i = 0; i < 3; i++) {
			sum += table[i][col] * ((pattern[pat]>>i)&1);
		}
		return sum;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		table = new int[3][n];
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < n; j++) {
				table[i][j] = scan.nextInt();
			}
		}
		dp = new int[n][4];
		for(int i = 0; i < 4; i++) {
			dp[0][i] = pebbleSum(0, i);
		}
		for(int col = 1; col < n; col++) {
			for(int pat = 0; pat < 4; pat++) {
				int max = -1000000000;
				for(int k = 0; k < 4; k++) {
					if((pattern[pat] & pattern[k]) != 0) continue;
					if(max < dp[col-1][k]) max = dp[col-1][k];
				}
				dp[col][pat] = max + pebbleSum(col, pat);
			}
		}
		int max = -1000000000;
		for(int i = 0; i < 4; i++) {
			if(max < dp[n-1][i]) max = dp[n-1][i];
		}
		System.out.println(max);
	}
}
