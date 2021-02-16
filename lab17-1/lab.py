def isPellin(r):
	t = len(r)
	for i in range(t//2):
		if r[i] != r[t-i-1]: return False
	return True

s = input()
r = ""
for i in range(len(s)):
	if isPellin(s[i:]):
		print(s+r)
		break
	r = str(s[i])+r
