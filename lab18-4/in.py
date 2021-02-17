import random
n = random.randrange(10000, 100000)
print(n)
v = [ i+1 for i in range(n) ]
random.shuffle(v)
for k in v:
	print(k, end=" ")
