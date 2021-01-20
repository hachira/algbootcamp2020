x = input().split()
n, k = int(x[0]), int(x[1])
sum = 0
for i in range(k, n+1, k):
	sum += i
print(sum)
