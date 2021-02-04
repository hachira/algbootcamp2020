import random
n = random.randrange(100, 10000)
print(n)
s = ""
for _ in range(n):
	s += str(random.randrange(1, 10000))+" "
print(s)
