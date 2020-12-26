a, b = input(), input()
na, nb = len(a), len(b)
dp = [[0]*(nb+1) for _ in range(na+1)]
for i in range(1, na+1):
	for j in range(1, nb+1):
		if a[i-1] == b[j-1]: dp[i][j] = dp[i-1][j-1]+1
		elif dp[i-1][j] > dp[i][j-1]: dp[i][j] = dp[i-1][j]
		else: dp[i][j] = dp[i][j-1]
print(dp[na][nb])
