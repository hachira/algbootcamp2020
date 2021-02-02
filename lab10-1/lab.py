#	N-Queen Solve
def checkQueen(varr, cur):
	#	check current queen with previous queens
	for i in range(cur):
		#	check row 
		if varr[i][0] == varr[cur][0]: return False
		#	check column
		if varr[i][1] == varr[cur][1]: return False
		#	check diagonals
		if varr[i][0]+varr[i][1] == varr[cur][0]+varr[cur][1]: return False
		if varr[i][0]-varr[i][1] == varr[cur][0]-varr[cur][1]: return False
	return True

def nQueen(varr, next, cur, n):
	#	Success N-Queen
	if cur == n: return 1
	sum = 0
	r, c = next
	while r < n:
		varr[cur] = (r, c)
		c += 1
		if c == n: r, c = r+1, 0
		if checkQueen(varr, cur): sum += nQueen(varr, (r, c), cur+1, n)
	return sum

n = int(input())
varr = [(0, 0) for _ in range(n)]
print(nQueen(varr, (0, 0), 0, n))
