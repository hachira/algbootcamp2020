# 피보나치 점화식을 그대로 구현한 재귀호출 프로그램
def fibo(n):
  if n == 0 : return 0
  if n == 1 : return 1
  return fibo(n-1) + fibo(n-2)

n = int(input())
print(fibo(n))

