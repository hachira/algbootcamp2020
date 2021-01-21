#include <stdio.h>

int main()
{
	int n, k, t;
	scanf("%d%d", &n, &k);
	int v[k];
	for(int i = 0; i < k; i++) scanf("%d", v+i);

	long long sum = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			if(i%v[j] == 0) {
				sum += i;
				break;
			}
		}
	}
	printf("%lld\n", sum);
}
					
