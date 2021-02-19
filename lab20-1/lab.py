n = int(input())
p = list(map(int, input().split()))
childs = [0]*n
for i in range(n):
	if p[i] != -1:
		childs[p[i]] += 1
k = int(input())
if p[k] != -1: childs[p[k]] -= 1
p[k] = -2
cnt = 0
for i in range(n):
	if childs[i] != 0: continue
	#	get root
	t = p[i]
	while t >= 0: t = p[t]
	if t == -1: cnt += 1
print(cnt)
