import random
n = random.randint(900000, 1000000)
print(n)
s = ""
for _ in range(n):
	s += str(random.randint(1, 100000)) + " "
print(s)
k = random.randint(90000, 100000)
print(k)
s = ""
for _ in range(k):
	a = random.randint(1, n)
	b = random.randint(1, n)
	if a > b: a, b = b, a
	print("%d %d"%(a, b))
