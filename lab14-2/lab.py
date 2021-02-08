#	Heap Sort
#	max heap heapify : 
#		v : array
#		n : data count
#		r : heap root
def heapify_recursion(v, n, r):
	max = r*2
	if max > n: return
	if max < n and v[max+1] > v[max]: max += 1
	if v[max] > v[r]:
		v[max], v[r] = v[r], v[max]
		heapify(v, n, max)

def heapify(v, n, r):
	while r*2 <= n:
		max = r*2
		if max < n and v[max+1] > v[max]: max += 1
		if v[max] <= v[r]: break
		v[max], v[r] = v[r], v[max]
		r = max

#	build heap
def buildHeap(v, n):
	for i in range(n//2, 0, -1):
		heapify(v, n, i)

n = int(input())
v = [0] + list(map(int, input().split()))

buildHeap(v, n)
for i in range(0, n):
	v[n-i], v[1] = v[1], v[n-i]
	heapify(v, n-i-1, 1)

for i in range(1, 16):
	print(v[i])
