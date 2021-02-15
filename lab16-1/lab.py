n = int(input())
a = tuple(map(int, input().split()))
dp = [0] * n
max = 1
for i in range(n):
	dp[i] = 1
	for j in range(i):
		if a[i] < a[j] and dp[i] <= dp[j]:
			dp[i] = dp[j] + 1
			if max < dp[i]: max = dp[i]
print(n-max)
