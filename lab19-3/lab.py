#	Brute force method
def gcd(a, b):
	while b > 0:
		a, b = b, a%b
	return a

n, m = map(int, input().split())
cnt = 0
for i in range(1, m+1):
	if gcd(n, i) == 1: cnt+=1
print(cnt)
