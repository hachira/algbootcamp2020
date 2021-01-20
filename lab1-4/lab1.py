def gcd(a, b):
	while b != 0:
		a, b = b, a%b
	return a

x = input().split()
n, a, b = int(x[0]), int(x[1]), int(x[2])
c = int(a//gcd(a, b) * b)
na = n//a
nb = n//b
nc = n//c
sum = a*na*(na+1)//2 + b*nb*(nb+1)//2 - c*nc*(nc+1)//2
print(sum)
