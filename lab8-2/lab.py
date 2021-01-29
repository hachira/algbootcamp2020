import queue

n = int(input())
adjMat = [[0]*(n+1) for _ in range(n+2)]
k = int(input())
for _ in range(k):
	a, b, w = map(int, input().split())
	adjMat[a][b] = w
start = int(input())

# prim algorithm
visited = [False]*(n+1)
values = [1000000]*(n+1)
queue = queue.PriorityQueue()
values[start] = 0
queue.put((0, start))
while not queue.empty():
	s, r = queue.get()
	if visited[r]: continue
	visited[r] = True
	for i in range(1, n+1):
		t = values[r] + adjMat[r][i]
		if adjMat[r][i] != 0 and not visited[i] and values[i] > t:
			values[i] = t
			queue.put((t, i))

for i in range(1, n+1):
	print(values[i])
