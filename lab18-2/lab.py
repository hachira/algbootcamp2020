#	back tracking method
def backtrack(start, sum, n):
	if sum==n: return 1
	r = 0
	for i in range(start, n+1):
		if sum+i > n: break
		r += backtrack(i, sum+i, n)
	return r

n = int(input())
print(backtrack(1, 0, n))

