def sosu(n):
    count = 0
    for i in range(1, n):
        if n % i == 0:
            count += 1
    if count == 1:
        return 1
    else:
        return 0
num = 0
n = int(input())
for i in range(2, n):
    if sosu(i) == 1:
        num += 1
print(num)
