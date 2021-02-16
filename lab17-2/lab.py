def isDecNumber(n):
	prev = -1
	while n > 0:
		t = n%10
		if t <= prev: return False
		prev, n = t, n//10
	return True

k = int(input())
for i in range(1, 9876543211):
	if isDecNumber(i):
		k -= 1
		if k == 0:
			print(i)
			break
