n = int(input())
adjMat = [[0]*n for _ in range(n)]
k = int(input())
for _ in range(k):
	a, b = map(int, input().split())
	adjMat[a-1][b-1] = 1
	adjMat[b-1][a-1] = 1

# print adjacent matrix
for i in range(n):
	s = ""
	for j in range(n):
		if adjMat[i][j] == 1: s+="1 "
		else: s+= "0 "
	print(s)

