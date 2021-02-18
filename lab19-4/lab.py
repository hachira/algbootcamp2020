#	Simulation
n, k = map(int, input().split())
v = list(map(int, input().split()))

person = 0
while True:
	step = 0
	for i in range(n):
		if v[i] == 0:
			step += 1
			if step == k: break
		else:
			step = 0
			v[i] -= 1
	if step == k: break
	person += 1
print(person)
