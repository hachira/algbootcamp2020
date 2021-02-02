#	N-Queen Solve
def checkQueen(varr, cur, row):
	#	check current queen with previous queens
	for i in range(cur):
		#	check row 
		if varr[i] == row: return False
		#	check diagonals
		if varr[i]+i == row+cur: return False
		if varr[i]-i == row-cur: return False
	return True

def nQueen(varr, cur, n):
	#	Success N-Queen
	if cur == n: return 1
	sum = 0
	for i in range(n):
		if checkQueen(varr, cur, i):
			varr[cur] = i
			sum += nQueen(varr, cur+1, n)
	return sum

n = int(input())
varr = [ 0 ]*n
print(nQueen(varr, 0, n))
