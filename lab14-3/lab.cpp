#include <stdio.h>

void mergeSort(int v[], int a, int b, int tmp[], bool out)
{
	if(a == b) { tmp[a] = v[a]; return; }
	int c = (a+b)/2;
	mergeSort(v, a, c, tmp, !out);
	mergeSort(v, c+1, b, tmp, !out);
	
	int *src, *dst;
	if(out) { dst = v; src = tmp; }
	else { dst = tmp; src = v; }
	int i = a, j = c+1, k = a;
	while(i <= c && j <= b)
	{
		if(src[i] < src[j]) dst[k++] = src[i++];
		else dst[k++] = src[j++];
	}
	while(i <= c) dst[k++] = src[i++];
	while(j <= b) dst[k++] = src[j++];
}

void mergeSort(int v[], int n)
{
	int *tmp = new int[n];
	mergeSort(v, 0, n-1, tmp, true);
}

int main()
{
	int n;
	scanf("%d", &n);
	int *v = new int[n];
	for(int i=0; i < n; i++) scanf("%d", v+i);

	mergeSort(v, n);
	for(int i=0; i < 15; i++) printf("%d ", v[i]); putchar('\n');
}
