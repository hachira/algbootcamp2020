# k가 입력되었을때, k번째 움직이는 하노이탑 원반을 계산해보자
def hanoi(n, k):
	if k <= 0: return k
	if n == 0: return k
	k = hanoi(n-1, k)
	k -= 1
	if k == 0:
		print(n)
		return 0
	k = hanoi(n-1, k)
	return k

k = int(input())
hanoi(32, k)

s = 1
for i in range(1, 32):
	if (k & s) != 0:
		print(i)
		break
	s *= 2
