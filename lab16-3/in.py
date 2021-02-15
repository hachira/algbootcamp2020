import random
n = random.randrange(50, 100)
print(n)
s = [ i for i in range(n+1) ]
random.shuffle(s)
k = random.randrange(n//2, n-3)
print(k)
v = [0]*(n+1)
for _ in range(k):
	while True:
		t = random.randrange(3, n)
		if v[t] == 0: break
	v[t] = 1
	p = random.randrange(1, t-1)
	print("%d %d"%(s[p], s[t]))

r = random.randrange(1, 10)
print(r)
for _ in range(r):
	t = random.randrange(1, n)
	p = random.randrange(1, n)
	print("%d %d"%(t, p))
