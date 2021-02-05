import random

n = random.randrange(100, 1000000)
print(n)
s = ""
for _ in range(n):
	s += str(random.randrange(100, 10000))+" "
print(s)
k = random.randrange(100, 10000)
print(k)
for _ in range(k):
	a = random.randrange(1, n)
	b = random.randrange(1, n)
	if a > b: a, b = b, a
	print("%d %d"%(a,b))
