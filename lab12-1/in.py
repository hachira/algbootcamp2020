import random
n = random.randrange(1000, 100000)
print(n)
s = ""
for _ in range(n):
	s += str(random.randrange(1, 10000))+" "
print(s)
