#include <stdio.h>

int partition(int v[], int a, int b)
{
	int pivot = v[b];
	int i = a, j = b-1;
	while(i <= j)
	{
		if(v[i] >= pivot) i++;
		else { int t = v[i]; v[i] = v[j]; v[j] = t; j--; }
	}
	v[b] = v[i]; v[i] = pivot;
	return i;
}

void subQuickSort(int v[], int a, int b, int k)
{
	if(a >= b) return;
	int c = partition(v, a, b);
	subQuickSort(v, a, c-1, k);
	if(k > c) subQuickSort(v, c+1, b, k);
}

int main()
{
	int n, k;
	scanf("%d", &n);
	int *v = new int[n];
	for(int i = 0; i < n; i++) scanf("%d", v+i);
	scanf("%d", &k);
	subQuickSort(v, 0, n-1, k-1);
	for(int i = 0; i < k; i++) printf("%d ", v[i]); putchar('\n');
}
