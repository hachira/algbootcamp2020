//	Recursion version with DP
#include <stdio.h>

const int MINF = -100000000;
int pattern[4] = { 1, 2, 4, 5 };
int dp[100][4];

int pebbleSum(int n, int p, int table[][3])
{
	if(n == 0) return 0;
	if(dp[n-1][p] != MINF) return dp[n-1][p];
	int max = MINF;
	for(int t = 0; t < 4; t++)
	{
		if(pattern[p] & pattern[t]) continue;
		int r = pebbleSum(n-1, t, table);
		if( r > max) max = r;
	}
	for(int i = 0; i < 3; i++) max += table[n-1][i]*((pattern[p]>>i)&1);
	return dp[n-1][p] = max;
}

int pebbleSum(int n, int table[][3])
{
	int max = MINF;
	for(int p = 0; p < 4; p++)
	{
		int r = pebbleSum(n, p, table);
		if(max < r) max = r;
	}
	return max;
}

int main()
{
	int n; 
	scanf("%d", &n);
	int table[n][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < n; j++) scanf("%d", &table[j][i]);
	for(int i = 0; i < n; i++)
		dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = MINF;

	printf("%d\n", pebbleSum(n, table));
}
