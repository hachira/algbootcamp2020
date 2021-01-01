import queue

INF = 1e9
v, e = map(int, input().split())
start = int(input())
adj = [[] for _ in range(v+1)]
for _ in range(e):
	a, b, c = map(int, input().split())
	adj[a].append((b, c))

node = [INF]*(v+1)
q = queue.PriorityQueue()
q.put((0, start))
node[start] = 0
while not q.empty():
	c, s = q.get()
	if node[s] < c: continue
	for k, w in adj[s]:
		if c + w < node[k]:
			node[k] = c+w
			q.put((c+w, k))
for k in range(1, v+1):
	print(node[k] if node[k] != INF else "INF")
