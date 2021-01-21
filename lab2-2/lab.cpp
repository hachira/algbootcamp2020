#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int v[n];
	for(int i=0;i<n;i++) scanf("%d", v+i);
	int min = 1000000000;
	int max = 1;
	for(int i=0;i<n-1;i+=2)
	{
		if(v[i]<v[i+1])
		{
			if(min>v[i]) min=v[i];
			if(max<v[i+1]) max=v[i+1];
		}
		else
		{
			if(min>v[i+1]) min=v[i+1];
			if(max<v[i]) max=v[i];
		}
	}
	if(n%2) {
		if(min>v[n-1]) min=v[n-1];
		if(max<v[n-1]) max=v[n-1];
	}
	printf("%d %d\n", min, max);
}
