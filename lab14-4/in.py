import random
n = random.randrange(100, 1000)
print(n)
k = 0
for i in range(n):
	if k == 0 or random.randrange(1, 5)%2 == 1:
		print("P %d"%random.randrange(1, 10000))
		k += 1
	else:
		print("G")
		k -= 1
