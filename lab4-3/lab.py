def isPelindrome(n):
	r = 0
	a = n
	while a > 0:
		r = r*10 + a%10;
		a //= 10
	return n == r

k = int(input())
s = 0
while k > 0:
	s += 1
	if isPelindrome(s):
		k -= 1
print(s)

