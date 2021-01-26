def fib(n):
	if n <= 1: return n
	return fib(n-2)+fib(n-1)

for k in range(1, 45):
	print("%d : %d"%(k, fib(k)))
