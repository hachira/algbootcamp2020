INF = 2000000000

def init(st, v, r, s, e):
	if s == e:
		st[r] = v[s]
		return st[r]
	c = (s+e)//2
	st[r] = min(init(st, v, r*2, s, c), init(st, v, r*2+1, c+1, e))
	return st[r]

def getMin(st, r, s, e, bs, be):
	if e < bs or be < s: return INF
	if bs <= s and e <= be: return st[r]
	c = (s+e)//2
	return min(getMin(st, r*2, s, c, bs, be), getMin(st, r*2+1, c+1, e, bs, be))

n = int(input())
v = tuple(map(int, input().split()))
st = [0]*(4*n)
init(st, v, 1, 0, n-1)
m = int(input())
for _ in range(m):
	a, b = map(int, input().split())
	print(getMin(st, 1, 0, n-1, a-1, b-1))
