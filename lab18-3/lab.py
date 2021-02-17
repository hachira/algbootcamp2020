MOD = 1000000007

def fib(n):
	f = [ 0, 1 ]
	for _ in range(2, n+1, 2):
		f[0] += f[1]
		f[1] += f[0]
	return f[n%2]

def gcd(a, b):
	while b > 0:
		a, b = b, a%b
	return a

a, b = map(int, input().split())
print(gcd(fib(a), fib(b))%MOD)
print(fib(gcd(a, b))%MOD)
