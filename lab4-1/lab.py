import random
#  Judge strkies and balls
def judge(think, guess):
	strike = 0
	ball = 0
	for i in range(3):
		if think[i] == guess[i]:
			strike += 1
			ball -= 1
		for j in range(3):
			if think[i] == guess[j]: ball += 1
	return strike, ball

think = []
for _ in range(3):
	r = random.randint(1, 9)
	while r in think: r = random.randint(1, 9)
	think.append(r)

strike = 0
score = 0
while strike != 3:
	print("Guess : ", end="")
	str = input()
	guess = [int(str[0:1]), int(str[1:2]), int(str[2:3])]
	strike, ball = judge(think, guess)
	print("%sS%sB"%(strike, ball))
	score += 1
print("Score : %d"%score)
