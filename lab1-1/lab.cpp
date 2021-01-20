#include <stdio.h>
int main()
{
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) sum += i;
	printf("%lld\n", sum);
}
