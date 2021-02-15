def gcd(a, b):
	while b > 0:
		a, b = b, a%b
	return a

def phi(n):
	count = 0
	for i in range(1, n):
		if gcd(n, i) == 1: count += 1
	return count

n = int(input())
print(phi(n))
