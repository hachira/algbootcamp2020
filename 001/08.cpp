#include <stdio.h>
using namespace std;

int solution(int n);

int main() {
    int n, count;
    scanf("%d", &n);
    count = solution(n);
    printf("%d\n", count);

    return 0;
}
int solution(int n) {
    int result = 0;
    int arr[n+1];

    for(int i=2; i<=n; i++)
        arr[i] = i;
    for(int i=2; i<=n; i++) {
        if(arr[i]==0) continue;
        for(int j=2*i; j<=n; j+=i)
            arr[j] = 0;
    }
    for(int i=2; i<=n; i++)
        if(arr[i]) result++;
        
    return result;
}
