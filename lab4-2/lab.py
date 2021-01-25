import random

#	judge strike and ball
def judge(a, b):
	strike, ball = 0, 0
	flag = 0
	c = a
	while c > 0:
		flag |= 1 << (c%10)
		c //= 10
	while a > 0:
		if (flag & (1 << (b%10))) != 0:
			if a%10 == b%10: strike += 1
			else: ball += 1
		a, b = a//10, b//10
	return strike, ball

#	Make candidate list
cand = []
for i in range(1, 10):
	for j in range(1, 10):
		if i == j: continue
		for k in range(1, 10):
			if i == k or j == k: continue
			cand.append(i*100+j*10+k)

#	Shuffle candidate list
random.shuffle(cand)

#	Guess and write history
history = []
score = 0
for i in range(len(cand)):
	isValid = True
	for k in history:
		s, b = judge(k[0], cand[i])
		if s != k[1] or b != k[2]:
			isValid = False
			break
	if not isValid: continue
	score += 1
	print("Guess : %d"%cand[i])
	s, b = map(int, input().split())
	if s == 3: break
	history.append((cand[i], s, b))
print("Score : %d"%score)
