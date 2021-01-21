n = int(input())
sum = 0
for i in range(1, int(n**0.5)+1):
    if n%i == 0:
        sum += i
        if i*i != n:
            sum += n//i
print(sum)

