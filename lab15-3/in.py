import random
n = random.randrange(10000000, 50000000)
print(n)
for _ in range(n):
	print(str(random.randrange(1, 100000000))+" ", end="")
print("")
print(random.randrange(1, 10000))
