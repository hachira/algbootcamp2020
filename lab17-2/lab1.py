N = int(input())
M = [[0] * 9 for _ in range(10)]
for i in range(10) :
  for j in range(9) :
    if i == 0 :
      M[i][j] = 1
    elif i > (j+1) : M[i][j] = 0
    elif i == (j+1) : 
      M[i][j] = 1
    else :
      M[i][j] = M[i-1][j-1] + M[i][j-1] 
def isDe(n) :
  S = str(n)
  c = 10
  for i in range(len(S)) :
    if int(S[i]) >= c : 
      return False
    c = int(S[i])
  return True
s = 0
for i in range(10) :
  for j in range(9) :
    prev = s 
    s += M[i][j]
    if N < s and prev <= N :
      # print(i,j,s,prev)
      k = prev+1
      n = 10**i*(j+1)
      while k <= N :
        n += 1
        if isDe(n) :
          # print(k," ",n)
          k+=1
      print(n)
      break

