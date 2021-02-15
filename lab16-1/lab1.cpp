#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int *v = new int[n];
	for(int i = 0; i < n; i++) scanf("%d", v+i);
	int k = 0;
	for(int i = 1; i < n; i++)
	{
		if(v[i] < v[k]) { v[++k] = v[i]; continue; }
		int first = 0, end = k;
		while(first < end)
		{
			int c = (first+end)/2;
			if(v[c] <= v[i]) end = c;
			else first = c+1;
		}
		v[first] = v[i];
	}
	printf("%d\n", n-k-1);
}
