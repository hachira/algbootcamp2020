#	Backtracking version
pattern = ( 1, 2, 4, 5 )

def value(col, p, tbl):
	sum = 0
	for i in range(3): sum += tbl[i][col]*((pattern[p]>>i)&1)
	return sum

def solve(n, tbl):
	#	Make dp 2-d array
	dp = [ [0]*4 for _ in range(n) ]
	#	Initialize first column
	for i in range(4): dp[0][i] = value(0, i, tbl)
	#	For other columns
	for i in range(1, n):
		#	For all patterns
		for j in range(4):
			max = -1000000000
			for k in range(4):
				# If pattern cannot be used by previous pattern
				if (pattern[j] & pattern[k]) != 0: continue
				if dp[i-1][k] > max: max = dp[i-1][k]
			dp[i][j] = max + value(i, j, tbl)
			
	max = dp[n-1][0]
	for i in range(1, 4):
		if dp[n-1][i] > max: max = dp[n-1][i]
	return max

n = int(input())
tbl = []
for _ in range(3):
	row = tuple(map(int, input().split()))
	tbl.append(row)

print(solve(n, tbl))
