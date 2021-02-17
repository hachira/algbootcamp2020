n = int(input())
arr = [0]+list(map(int, input().split()))
DP = [0]*(n+1)
 
for i in range(1,n+1):
    for j in range(1, i, 1):
        if arr[i] > arr[i-j]:
            DP[i] = max(DP[i-j], DP[i])
    DP[i] += 1
# print(DP)
print(n - max(DP))

