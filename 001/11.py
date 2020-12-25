# 소수의 개수 출력 

num = int(input())
count = 0
cnt_list = [0]*(num+1)
for i in range(2, num+1):
    if cnt_list[i]==0:
        count += 1
        for j in range(i , num+1 , i ):
            cnt_list[j] = 1
    
print(count)
