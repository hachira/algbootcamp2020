import random
v = random.randrange(2, 20001)
e = random.randrange(v-1, 300001)
print("%d %d"%(v, e))
print(random.randrange(1, v+1))
for i in range(0, e):
	start = random.randrange(1, v+1)
	end = random.randrange(1, v)
	if end >= start: end += 1
	print("%d %d %d"%(start, end, random.randrange(1, 11)))
