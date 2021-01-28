def perm(s, n, r, v):
	if r == 0:
		print(s)
		return
	for i in range(n):
		if v[i]: continue
		v[i] = True
		perm(s+str(i+1), n, r-1, v)
		v[i] = False

n, r = map(int, input().split())
v = [False]*n
perm("", n, r, v)
