import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		char[] st1 = sc.nextLine().toCharArray();
		char[] st2 = sc.nextLine().toCharArray();

		int[][] dp = new int[st1.length + 1][st2.length + 1];

		for (int i = 1; i <= st1.length; i++) {
			for (int j = 1; j <= st2.length; j++) {
				if (st1[i - 1] == st2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} 
				else {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		System.out.println(dp[st1.length][st2.length]);

	}

}
