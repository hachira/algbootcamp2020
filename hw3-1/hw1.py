def getSum(n) :
	while n >= 10:
		sum = 0 
		while n > 0:
			sum += n%10
			n //= 10
		n = sum
	return n

def fact(n):
	f = 1
	for i in range(1, n+1):
		f *= i
	return f

n = int(input())
print(getSum(fact(n)))
