def pibonacci(n):
    i, j = 0, 1

    while n > 0:
        i, j = j, i+j
        n -= 1
    return i

n = int(input())
print(pibonacci(n))
