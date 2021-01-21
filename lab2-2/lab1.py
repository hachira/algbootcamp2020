n = int(input())
v = list(map(int, input().split()))

min = 1000000000
max = 1
for i in range(0, len(v)-1, 2):
	if v[i] < v[i+1]:
		if min > v[i]: min = v[i]
		if max < v[i+1]: max = v[i+1]
	else:
		if min > v[i+1]: min = v[i+1]
		if max < v[i]: max = v[i]
if n%2==1:
	if min>v[-1]: min=v[-1]
	if max<v[-1]: max=v[-1]

print("%d %d"%(min, max))
