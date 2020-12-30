def fib(n):
    if n <= 1:
        return n
    else:
        return fib(n-2) + fib(n-1)

n = int(input())
print(fib(n))
