import random
a = int(input())
b = int(input())
s = ""
for i in range(0, a):
	s+=chr(random.randrange(65,65+26))
print(s)
s = ""
for i in range(0, b):
	s+=chr(random.randrange(65,65+26))
print(s)
