def init(st, r, v, s, e):
	if s==e:
		st[r] = v[s]
		return st[r]
	c = (s+e)//2
	st[r] = init(st, r*2, v, s, c)+init(st, r*2+1, v, c+1, e)
	return st[r]

def sum(st, r, s, e, ss, ee):
	if ee < s or e < ss: return 0
	if ss <= s and e <= ee: return st[r]
	c = (s+e)//2
	return sum(st, r*2, s, c, ss, ee) + sum(st, r*2+1, c+1, e, ss, ee)

def update(st, r, s, e, idx, v):
	if idx < s or e < idx: return st[r]
	if s == e:
		st[r] = v
		return st[r]
	c = (s+e)//2
	st[r] = update(st, r*2, s, c, idx, v) + update(st, r*2+1, c+1, e, idx, v)
	return st[r]

n = int(input())
v = tuple(map(int, input().split()))

st = [0]*(4*n)
init(st, 1, v, 0, n-1)

k = int(input())
for _ in range(k):
	x = input().split()
	a, b = int(x[1]), int(x[2])
	if x[0] == "s": print(sum(st, 1, 0, n-1, a-1, b-1))
	else: update(st, 1, 0, n-1, a-1, b)
