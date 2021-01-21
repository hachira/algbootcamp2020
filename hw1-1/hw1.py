n, k = map(int, input().split())
v = list(map(int, input().split()))

vv = set()
for j in v:
	for i in range(j, n+1, j):
		vv.add(i)

sum = sum(vv)
print(sum)
