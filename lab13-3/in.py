import random

n = random.randrange(100, 1000000)
print(n)
s = ""
for _ in range(n):
	s += str(random.randrange(1, 10000))+" "
print(s)
k = random.randrange(100, 10000)
print(k)
for _ in range(k):
	if random.randrange(1, 2) == 1:
		a = random.randrange(1, n)
		b = random.randrange(1, n)
		if a > b: a, b = b, a
		print("s %d %d"%(a,b))
	else: 
		a = random.randrange(1, n)
		b = random.randrange(1, 10000)
		print("u %d %d"%(a,b))
