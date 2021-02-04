F = ( 1, 1, 1, 0 )
MOD = 1000000009

def mult(a, b):
	return ((a[0]*b[0]+a[1]*b[2])%MOD, 
		(a[0]*b[2]+a[1]*b[3])%MOD,
		(a[2]*b[0]+a[3]*b[2])%MOD, 
		(a[2]*b[2]+a[3]*b[3])%MOD)

def fibo(n):
	if n == 1: return F
	t = fibo(n//2)
	t = mult(t, t)
	if n%2 == 1:
		t = mult(t, F)
	return t
	
n = int(input())
print(fibo(n)[2])
