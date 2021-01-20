x = input().split()
n, a, b = int(x[0]), int(x[1]), int(x[2])
sum = 0
for i in range(1,n+1):
    if i%a==0 or i%b==0:
        sum+=i
print(sum)
