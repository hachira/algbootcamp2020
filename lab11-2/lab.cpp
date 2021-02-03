//	Non recursion version with DP
#include <stdio.h>

int *dp;
int solve(int n, int coins[], int k)
{
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int min = i;
		for(int j = 0; j < k; j++)
		{
			if(i < coins[j]) continue;
			if(dp[i-coins[j]] < min) min = dp[i-coins[j]];
		}
		dp[i] = min+1;
	}
	return dp[n];
}

int main()
{
	int k, n;
	scanf("%d", &k);
	int coins[k];
	for(int i = 0; i < k; i++) scanf("%d", coins+i);
	scanf("%d", &n);
	dp = new int[n+1];
	printf("%d\n", solve(n, coins, k));
	delete[] dp;
}
