# Fibonacci 수열을 해보자
# 가장 효율이 안 좋은 방법. 점화식을 이용해서 구하기

def fib(n):
	if n==0: return 0
	if n==1: return 1
	return fib(n-1)+fib(n-2)

n = int(input())
print(fib(n))
