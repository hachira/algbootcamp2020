import queue

n = int(input())
vert = [0]*(n+1)
k = int(input())
adjList = [ [] for _ in range(n+1) ]
for _ in range(k):
	a, b = map(int, input().split())
	adjList[a].append(b)
	vert[b] += 1

# Create queue
que = queue.Queue()

# Find vert[k] = 0 and Add k to queue
for i in range(1, n+1):
	if vert[i] == 0: que.put(i)

vertCount = 0
s = ""
while not que.empty():
	r = que.get()
	s += str(r) + " "
	vertCount += 1
	for k in adjList[r]:
		vert[k] -= 1
		if vert[k] == 0: que.put(k)

if vertCount != n: print("Error")
else: print(s)
