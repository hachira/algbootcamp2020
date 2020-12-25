import math
def pi(n):
	if n < 2: return 0
	if n == 2: return 1
	pn = 1
	s = [0]*(n+1)
	for i in range(3, n+1, 2):
		if s[i] == 1: continue
		pn+=1
		for j in range(i*i, n+1, i*2):
			s[j] = 1
	return pn

n = int(input())
print(pi(n))
