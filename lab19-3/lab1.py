n, m = map(int, input().split())

v = [False]*n
v[0] = True

t, p = n, 3
if t%2 == 0:
	for i in range(2, n, 2): v[i] = True
	while t%2 == 0: t //= 2

while p*p <= t:
	if t%p == 0:
		for i in range(p, n, p): v[i] = True
		while t%p == 0: t //= p
	p += 2

if t > 1:
	for i in range(t, n, t): v[i] = True

cnt1 = 0
for i in range(n):
	if not v[i]: cnt1 += 1

cnt = cnt1*( (m+1)//n )
for i in range(1, (m+1)%n):
	if not v[i]: cnt += 1

print(cnt)
