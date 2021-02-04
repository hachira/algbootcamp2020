#	Divide and Conquer Algorithm for Maximum Rectangle Area at Histogram
def divideAndConquer(hist, a, b):
	if a == b: return hist[a]
	#	Divide
	c = (a+b)//2
	max = divideAndConquer(hist, a, c)
	r = divideAndConquer(hist, c+1, b)
	if max < r: max = r

	#	Conquer
	min = hist[c]
	if min > hist[c+1]: min = hist[c+1]
	i, j, w = c-1, c+2, 2
	if max < min*w: max = min*w
	while i >= a and j <= b:
		if hist[i] > hist[j]:
			if min > hist[i]: min = hist[i]
			i -= 1
		else:
			if min > hist[j]: min = hist[j]
			j += 1
		w += 1
		if max < min*w: max = min*w
	while i >= a:
		if min > hist[i]: min = hist[i]
		i -= 1
		w += 1
		if max < min*w: max = min*w
	while j <= b:
		if min > hist[j]: min = hist[j]
		j += 1
		w += 1
		if max < min*w: max = min*w
	return max

n = int(input())
hist = tuple(map(int, input().split()))
print(divideAndConquer(hist, 0, n-1))
