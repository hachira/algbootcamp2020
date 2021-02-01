"""
Floyd Washall Algorithm
"""
INF = 1000000000
n = int(input())

# 거리를 저장할 n x n 배열 선언
d = [ [INF]*(n+1) for _ in range(n+1) ]

# 경로를 저장하기 위한 n x n 배열 선언
next = [ [ k for k in range(n+1) ] for _ in range(n+1) ]

# 대각 배열값을 0으로 초기화
for i in range(1, n+1): d[i][i] = 0

k = int(input())
for _ in range(k):
	a, b, w = map(int, input().split())
	d[a][b] = w

#  Floyd Washall Algorithm
for m in range(1, n+1):
	for u in range(1, n+1):
		for v in range(1, n+1):
			if d[u][m] == INF or d[m][v] == INF: continue
			if d[u][v] > d[u][m] + d[m][v]:
				d[u][v] = d[u][m] + d[m][v]
				next[u][v] = next[u][m]

#  음의 사이클이 있는지 검사
isMinusCycle = False
for i in range(1, n+1):
	if d[i][i] < 0:
		isMinuscycle = True
		break;
if isMinusCycle:
	print("Minus Cycle detected");
	quit()

# print
for u in range(1, n+1):
	s = ""
	for v in range(1, n+1):
		if d[u][v] == INF: s += "INF "
		else: s += "%3d "%d[u][v]
	print(s)

# print path
u, v = 1, 7
path = [u]
while u != v:
	u = next[u][v]
	path += [u]
print(path)

