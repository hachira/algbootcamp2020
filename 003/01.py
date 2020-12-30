def pibo(N):
    a, b = 0, 1
    
    while N > 0:
        a, b = b, a+b
        N -= 1
    return a

N = int(input())
print(pibo(N))
