import statistics

#	Brute force method
n, k = map(int, input().split())
v = tuple(map(int, input().split()))
sum = 0
for i in range(n-k+1):
	sum += int(statistics.median(v[i:i+k]))
print(sum)
