MOD = 1000000009

n = int(input())

f = [0, 1]
for k in range(2, n+1, 2):
	f[0] = (f[0]+f[1])%MOD
	f[1] = (f[0]+f[1])%MOD

print(f[n%2])
