#	Pure Dynamic Programming for solving Fibonacci Series
dp = [0]*100

def fibo(n):
  if n == 0 : return 0
  if n == 1 : return 1
  if dp[n] != 0: return dp[n]
  dp[n] = fibo(n-1) + fibo(n-2)
  return dp[n]

n = int(input())
print(fibo(n))

