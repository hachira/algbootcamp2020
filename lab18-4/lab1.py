n = int(input())
v = list(map(int, input().split()))
k = 0
for i in range(1, n):
	if v[i] > v[k]:
		k += 1
		v[k] = v[i]
		continue
	s, e = 0, k
	while s < e:
		c = (s+e)//2
		if v[c] < v[i]: s = c+1
		else: e = c
	v[s] = v[i]
print(n-k-1)
