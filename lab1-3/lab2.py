def gcd(a, b):
	while b != 0:
		a, b = b, a%b
	return a

a, b = map(int, input().split())
if a < b: a, b = b, a
print(gcd(a,b))

