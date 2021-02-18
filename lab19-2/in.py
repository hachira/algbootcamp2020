import random
k = random.randrange(11, 2000)*2 + 1
n = random.randrange(k, 100000)
print("%d %d"%(n, k))
for _ in range(n):
	print(random.randrange(1, 10000), end=" ")
