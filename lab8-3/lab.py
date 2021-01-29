INF = 1000000000
n = int(input())
k = int(input())
edges = []
for i in range(k):
	a, b, w = map(int, input().split())
	edges.append((a, b, w))
start = int(input())

values = [INF]*(n+1)
values[start] = 0
for _ in range(n):
	dirty = False
	for e in edges:
		if values[e[0]] == INF: continue
		t = values[e[0]] + e[2]
		if values[e[1]] > t:
			values[e[1]] = t
			dirty = True
	if not dirty: break

if dirty:
	print("Invalid Graph")
	quit()

for i in range(1, n+1):
	print(values[i])
