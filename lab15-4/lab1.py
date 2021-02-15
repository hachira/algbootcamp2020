def gcd(a, b):
	while b > 0:
		a, b = b, a%b
	return a

def phi(n):
	phi = 1
	if n%2 == 0:
		n //= 2
		while n%2 == 0:
			phi, n = phi*2, n//2
	p = 3
	while p*p < n:
		if n%p == 0:
			n //= p
			phi *= p-1
			while n%p == 0:
				phi, n = phi*p, n//p
		p += 2
	if n > 1: return (n-1)*phi
	return phi

n = int(input())
print(phi(n))
