# 주어진 수에 대한 약수의 합을 구해보자
n = int(input())

s1 = 1
if n%2 == 0:
	s = 1
	while n%2 == 0:
		s = s*2 + 1
		n //= 2
	s1 *= s
i = 3
while i*i <= n:
	if n%i != 0:
		i += 2
		continue
	s = 1
	while n%i == 0:
		s = s*i + 1
		n //= i
	s1 *= s
	i += 2
if n > 1: s1 *= n+1

print(s1)
