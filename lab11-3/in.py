import random
n = random.randrange(10, 30)
print(n)
for _ in range(3):
	s = ""
	for i in range(n):
		s += str(random.randrange(-100, 100))+" "
	print(s)
