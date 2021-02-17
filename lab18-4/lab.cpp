#include <cstdio>
#include <algorithm>

int main()
{
	int n, t, k = 1;
	scanf("%d", &n);
	int *v = new int[n];
	scanf("%d", v);
	for(int i = 1; i < n; i++)
	{
		scanf("%d", &t);
		if(v[k-1] < t) v[k++] = t;
		else
		{
			int *s = std::lower_bound(v, v+k, t);
			*s = t;
		}
	}
	printf("%d\n", n-k);
}
