n = int(input())
v = list(map(int, input().split()))

min = v[0]
max = v[0]
for k in v:
	if min > k: min = k
	if max < k: max = k

print("%d %d"%(min, max))
