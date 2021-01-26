# 입력부 처리
n = int(input())
v = tuple(map(int, input().split()))
k = int(input())

# 누적합을 리스트로 미리 만들도록 한다
sumlist = [0]
sum = 0
for i in range(n):
	sum += v[i]
	sumlist.append(sum)

# k 구간에 대해서 합 계산
for _ in range(k):
	a, b = map(int, input().split())
	print(sumlist[b] - sumlist[a-1])
