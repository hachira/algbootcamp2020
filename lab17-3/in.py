import random
n = random.randrange(10000, 20000)
print(n)
for _ in range(n):
	print(str(random.randrange(1, 1000000))+" ", end="")
print("")
