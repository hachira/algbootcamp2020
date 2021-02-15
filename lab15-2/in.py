import random
n = random.randrange(10000, 100000000)
print(n)
s = ""
for _ in range(n):
	s += str(random.randrange(1, 100000000))+" "
print(s)
k = random.randrange(1, n)
print(k)
