a = str(input())
b = str(input())

count = []
for i in a:
    for j in b:
       if i == j:
           count.append(i)

print(len(count))
