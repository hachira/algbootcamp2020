#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int v[n];
	for(int i=0;i<n;i++) scanf("%d",v+i);

	int min = v[0];
	for(int i=1;i<n;i++) if(min>v[i]) min=v[i];

	printf("%d\n", min);
}
