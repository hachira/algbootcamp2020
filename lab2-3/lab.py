n = int(input())

# 가장 수학정의에 맞는 알고리즘은 다음과 같습니다.
nodiv = 0
for i in range(1, n+1):
	if n%i == 0: nodiv+=1

print(nodiv)
