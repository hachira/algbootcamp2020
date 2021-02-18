s, p = map(int, input().split())
if s == p:
	print("1")
	quit()
last = s
n = 2
while True:
	maxp = (s/n)**n
	if maxp < last:
		print("-1")
		break
	if maxp >= p:
		print(n)
		break
	n += 1
	last = maxp
