#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	long long sum = (long long)n*(n+1)/2;
	printf("%lld\n", sum);
}
