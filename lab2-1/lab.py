n = int(input())
v = list(map(int, input().split()))

min = v[0]
for i in range(1, n):
	if min > v[i]: min = v[i]

print(min)
