#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i%k == 0) sum += i;
	}
	printf("%lld\n", sum);
}
