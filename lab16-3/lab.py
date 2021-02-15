n = int(input())
p = [-1]*(n+1)
k = int(input())
for _ in range(k):
	a, b = map(int, input().split())
	p[b] = a

r = int(input())
for _ in range(r):
	a, b = map(int, input().split())
	v = [0]*(n+1)
	v[a] = 1
	while p[a] != -1:
		v[p[a]] = v[a]+1
		a = p[a]
	s = -1 
	found = False
	while b != -1:
		if v[b] != 0:
			found = True
			break
		s += 1
		b = p[b]
	if found: print(s+v[b])
	else: print(-1)
