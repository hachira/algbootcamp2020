n =int(input())
row = [0] * n
result = 0
def check(x) :
  for i in range(x):
    if row[x] == row[i] or  abs(row[x]-row[i]) == x- i:
      return False
  return True
        
def nQueen(x) :
  global result
  if x == n :
    result += 1; # print(row)
  else:
    for i in range(n):
      row[x] = i
      if check(x):
        nQueen(x+1)
nQueen(0)
print(result)

