def pelindrome(n):
	r = ""
	while n > 0:
		r += str(n%10)
		n //= 10
	return r

k = int(input())
if k <= 9:
	print(k)
	quit()
k -= 10
iv, ist, tv = 9, 2, 1
while True:
	if k < iv: break
	k -= iv
	if ist%2 == 1: tv *= 10
	else: iv *= 10
	ist += 1
if ist%2 == 1:
	f = k/10+tv
	print("%s%s%s"%(f, k%10, pelindrome(f)))
else:
	k += tv
	print("%s%s"%(k, pelindrome(k)))
