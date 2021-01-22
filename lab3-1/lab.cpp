#include <stdio.h>

long long hanoi(int n)
{
	if(n==1) return 1;
	return hanoi(n-1)*2+1;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld", hanoi(n));
}
