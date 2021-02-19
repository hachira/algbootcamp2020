def init_st(st, r, s, e, n):
	if s == e: 
		if 1 <= s and s <= n: st[r] = 1
		else: st[r] = 0
		return st[r]
	c = (s+e)//2
	st[r] = init_st(st, r*2, s, c, n) + init_st(st, r*2+1, c+1, e, n)
	return st[r]

def sum_st(st, r, s, e, sb, eb):
	if e < sb or eb < s: return 0
	if sb <= s and e <= eb: return st[r]
	c = (s+e)//2
	return sum_st(st, r*2, s, c, sb, eb) + sum_st(st, r*2+1, c+1, e, sb, eb)

def update_st(st, r, s, e, idx, x):
	if idx < s or e < idx: return st[r]
	if s == e:
		st[r] = x
		return st[r]
	c = (s+e)//2
	st[r] = update_st(st, r*2, s, c, idx, x)+update_st(st, r*2+1, c+1, e, idx, x)
	return st[r]

n = int(input())
m = int(input())
st = [0]*(4*(n+m))
idx = [n-i+1 for i in range(n+1)]
init_st(st, 1, 0, n+m, n)
for i in range(1, m+1):
	t = int(input())
	print(sum_st(st, 1, 0, n+m, idx[t], n+m))
	update_st(st, 1, 0, n+m, idx[t], 0)
	idx[t] = n+i
	update_st(st, 1, 0, n+m, idx[t], 1)
