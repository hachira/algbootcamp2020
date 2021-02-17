import random
n = random.randrange(10000, 100000)
print(n)
for _ in range(n):
	v = random.randrange(1, 100000)
	print(str(v)+" ", end="")
print("")
m = random.randrange(1000, 10000)
print(m)
for _ in range(m):
	a = random.randrange(1, n)
	b = random.randrange(a, n)
	print("%d %d"%(a, b))
