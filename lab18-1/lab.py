n = int(input())
v = tuple(map(int, input().split()))
m = int(input())
for _ in range(m):
	a, b = map(int, input().split())
	min = v[a-1]
	for i in range(a, b):
		if min > v[i]: min = v[i]
	print(min)
