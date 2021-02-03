#	Backtracking version
pattern = ( 1, 2, 4, 5 )
def solve(cur, last, n, sum, tbl):
	if cur == n: return sum
	max = -1000000000
	for p in pattern:
		if (p & last) != 0: continue
		nsum = sum;
		for i in range(3): nsum += tbl[i][cur] * ((p>>i)&1)
		r = solve(cur+1, p, n, nsum, tbl)
		if max < r: max = r
	return max


n = int(input())
tbl = []
for _ in range(3):
	row = tuple(map(int, input().split()))
	tbl.append(row)

print(solve(0, 0, n, 0, tbl))
