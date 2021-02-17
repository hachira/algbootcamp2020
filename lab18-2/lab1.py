#	dynamic programmin method

n = int(input())
dp = [1]*(n+1)
for i in range(2, n):
	for j in range(n, 1, -1):
		for k in range(j-i, -1, -i):
			dp[j] += dp[k]
if n != 1: dp[n] += 1
print(dp[n])
