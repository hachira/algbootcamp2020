n = int(input())
v = list(map(int, input().split()))
sum = [0]
for i in range(n): sum += [ sum[i]+v[i] ]
k = int(input())
for _ in range(k):
	x = input().split()
	a, b = int(x[1]), int(x[2])
	if x[0] == "s":
		print(sum[b] - sum[a-1])
	else:
		v[a-1] = b
		for i in range(a, n+1):
			sum[i] = sum[i-1] + v[i-1]
