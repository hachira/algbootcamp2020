def isPelindrome(n):
	r = 0
	a = n
	while a > 0:
		r = r*10 + a%10;
		a //= 10
	return n == r

def A002113_list(nMax):
  mlist=[]
  for n in range(nMax+1):
     mstr=str(n)
     if mstr==mstr[::-1]:
        mlist.append(n)
  return(mlist)

print(A002113_list(40))

