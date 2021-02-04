#	Brute force Algorithm for histogram
n = int(input())
hist = tuple(map(int, input().split()))

max = 0
for i in range(n):
	#	If previous histogram value is greater than current,
	#	starting index i cannot be get better result than starting previous index. 
	if i > 0 and hist[i-1] >= hist[i]: continue
	min = hist[i]
	for j in range(i+1, n):
		if min > hist[j]: min = hist[j]
		area = min*(j-i+1)
		if area > max: max = area

print(max)
