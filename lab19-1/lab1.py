import math
s, p = map(int, input().split())

#	if S equals P, than n = 1
if s == p:
	print(1)
	quit()

#	Get patition number of maximum product
n = int(s*math.exp(-1))
if math.pow(s/n, n) < math.pow(s/(n+1), n+1): n += 1

#	if max value is below P, there is no solution
maxvalue = int(math.pow(s/n, n))
if p > maxvalue:
	print(-1)
	quit()

#	Binary Search
left, right = 2, n
while left < right:
	c = (left+right)//2
	v = int(math.pow(s/c, c))
	if p <= v: right = c
	else: left = c+1
print(right)
