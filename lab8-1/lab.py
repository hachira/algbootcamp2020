def findRoot(set, x):
	if set[x] == x: return x
	set[x] = findRoot(set, set[x])
	return set[x]

n = int(input())
k = int(input())

edges = []
for _ in range(k):
	a, b, w = map(int, input().split())
	edges.append((a, b, w))

edges.sort(key=lambda x : x[2])

set = [ i for i in range(n+1) ]
complete = 0
sum = 0
for e in edges:
	ra = findRoot(set, e[0])
	rb = findRoot(set, e[1])
	if ra == rb: continue
	set[rb] = ra
	sum += e[2]
	complete += 1
	if complete == n-1: break

print(sum)
