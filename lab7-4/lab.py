import queue

n = int(input())
adjMat = [[0]*n for _ in range(n)]
k = int(input())
for _ in range(k):
	a, b, w = map(int, input().split())
	adjMat[a-1][b-1] = w
	adjMat[b-1][a-1] = w

# prim algorithm
visited = [False]*n
values = [1000000]*n
queue = queue.PriorityQueue()
values[0] = 0
queue.put((0, 0))
sum = 0
while not queue.empty():
	s, r = queue.get()
	if visited[r]: continue
	print("vertex : %d, value = %d"%(r, s))
	visited[r] = True
	sum += s
	for i in range(n):
		if adjMat[r][i] != 0 and not visited[i] and values[i] > adjMat[r][i]:
			values[i] = adjMat[r][i]
			queue.put((values[i], i))
print(sum)
