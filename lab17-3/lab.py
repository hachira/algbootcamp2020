count = 0

def bubbleSort(v, n):
	global count
	for i in range(1, n):
		dirty = False
		for j in range(n-i):
			if v[j] > v[j+1]:
				v[j], v[j+1] = v[j+1], v[j]   # Swap(...)
				count += 1
				dirty = True
		if not dirty: return

n = int(input())
v = list(map(int, input().split()))
#bubbleSort(v, n)
for i in range(n-1):
	for j in range(i+1, n):
		if v[i] > v[j]: count += 1
print(count)
