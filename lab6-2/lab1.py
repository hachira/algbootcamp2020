n = int(input())
adjList = [[] for _ in range(n)]
k = int(input())
for _ in range(k):
	a, b = map(int, input().split())
	adjList[a-1] += [b]
	adjList[b-1] += [a]

# print adjacent list
for i in range(n):
	s = str(i+1)+" : "
	for k in adjList[i]:
		s += str(k)+" "
	print(s)

