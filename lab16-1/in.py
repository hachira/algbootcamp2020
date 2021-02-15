import random
n = random.randrange(10000, 100000)
print(n)
for _ in range(n):
	print("%d "%random.randrange(1, 1000000), end="")
print("")
