MOD = 1000000009
n = int(input())
f = [[1,1],
      [1,0]]
def matrixmul(a, b) :
  c = [[0,0],[0,0]]
  c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0] ) % MOD
  c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD
  c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD
  c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD
  return c
def fibo(n) :
  if n == 1 : return f
  temp = n//2 
  # print(n)
  r = fibo(temp)
  r = matrixmul(r, r)
  if n % 2 == 1: 
    r = matrixmul(r, f)
  return r 
print(fibo(n)[0][1])
