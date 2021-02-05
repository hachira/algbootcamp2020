n = int(input())
v = tuple(map(int, input().split()))
k = int(input())
for _ in range(k):
	a, b = map(int, input().split())
	sum = 0
	for i in range(a-1, b):
		sum += v[i]
	print(sum)
