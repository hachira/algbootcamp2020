import java.util.*;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) v[i] = scan.nextInt();
		int[] dp = new int[n];
		dp[0] = v[0];
		int max = 1;
		for(int i = 1; i < n; i++) {
			if(v[i] < dp[max-1]) dp[max++] = v[i];
			else {
				int j;
				for(j = 0; j < max; j++) {
					if(v[i] >= dp[j]) break;
				}
				dp[j] = v[i];
			}
		}
		System.out.println(n-max);
	}
}
