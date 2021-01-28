def findRoot(v, x):
	if v[x] == x: return x
	v[x] = findRoot(v, v[x])
	return v[x]

n = int(input())
k = int(input())
v = [i for i in range(n)]
rank = [1 for i in range(n)]
for i in range(k):
	x = input().split()
	if x[0] == "u":
		a = int(x[1])-1
		b = int(x[2])-1
		ra = findRoot(v, a)
		rb = findRoot(v, b)
		if rank[ra] >= rank[rb]:
			v[rb] = ra
			rank[ra] += rank[rb]
		else:
			v[ra] = rb
			rank[rb] += rank[ra]
	elif x[0] == "t":
		a = int(x[1])-1
		b = int(x[2])-1
		ra = findRoot(v, a)
		rb = findRoot(v, b)
		if ra == rb: print("true")
		else: print("false")
