#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d", &n);
	int v[n];
	for(int i = 0; i < n; i++) scanf("%d", v+i);
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		char cmd[16]; int a, b;
		scanf("%s%d%d", cmd, &a, &b);
		if(cmd[0] == 's')
		{
			long long sum = 0;
			for(int i = a-1; i < b; i++) sum += v[i];
			printf("%lld\n", sum);
		}
		else
		{
			v[a-1] = b;
		}
	}
}
