import queue

def dfs(r, n, adjMat, visited):
	visited[r] = True
	print(r+1)
	for i in range(n):
		if adjMat[r][i] == 1 and not visited[i]:
			dfs(i, n, adjMat, visited)

n = int(input())
adjMat = [[0]*n for _ in range(n)]
k = int(input())
for _ in range(k):
	a, b = map(int, input().split())
	adjMat[a-1][b-1] = 1
	adjMat[b-1][a-1] = 1

# dfs
print("dfs")
visited = [False]*n
dfs(0, n, adjMat, visited)

# bfs
print("bfs")
visited = [False]*n
queue = queue.Queue()
queue.put(0)
visited[0] = True
while not queue.empty():
	r = queue.get()
	print(r+1)
	for i in range(n):
		if adjMat[r][i] == 1 and not visited[i]:
			queue.put(i)
			visited[i] = True
