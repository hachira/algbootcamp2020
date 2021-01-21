n, k = map(int, input().split())
v = list(map(int, input().split()))

sum = 0
for i in range(1, n+1):
	for j in v:
		if i%j == 0:
			sum += i
			break

print(sum)
