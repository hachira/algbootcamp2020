#	Quick sort
def partition(v, a, b):
	pivot = v[b]
	i, j = a, b-1
	while i <= j:
		if v[i] <= pivot: i += 1
		else:
			v[i], v[j] = v[j], v[i]
			j -= 1
	v[i], v[b] = v[b], v[i]
	return i

def quickSort(v, a, b):
	if a >= b: return
	c = partition(v, a, b)
	quickSort(v, a, c-1)
	quickSort(v, c+1, b)

n = int(input())
v = list(map(int, input().split()))
quickSort(v, 0, n-1)
for i in range(15):
	print(v[i])
