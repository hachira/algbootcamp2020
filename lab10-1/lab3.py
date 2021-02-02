#	N-Queen Solve
def checkQueen(varr, cur, row, n, flag):
	#	check row
	if flag[0][row]: return False
	#	check diagonals
	if flag[1][row+cur]: return False
	if flag[2][row+n-cur-1]: return False
	return True

def nQueen(varr, cur, n, flag):
	#	Success N-Queen
	if cur == n: return 1
	sum = 0
	for i in range(n):
		if checkQueen(flag, cur, i, n, flag):
			varr[cur] = i
			flag[0][i] = True
			flag[1][i+cur] = True
			flag[2][i+n-cur-1] = True
			sum += nQueen(varr, cur+1, n, flag)
			flag[0][i] = False
			flag[1][i+cur] = False
			flag[2][i+n-cur-1] = False
	return sum

n = int(input())
varr = [ 0 ]*n
# initialize flag
flag = [ [False]*(2*n) for _ in range(3) ]
print(nQueen(varr, 0, n, flag))
