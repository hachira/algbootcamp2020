import random
n = random.randrange(10000, 100000)
print(n)
s = ""
for _ in range(n):
	s += str(random.randrange(1, 1000000))+" "
print(s)
