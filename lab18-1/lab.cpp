#include <stdio.h>
#define	INF	2000000000

int min(int a, int b) { return a<b?a:b; }

int init(int st[], int r, int s, int e, int v[])
{
	if(s == e) return st[r] = v[s];
	int c = (s+e)/2;
	return st[r] = min(init(st, r*2, s, c, v), init(st, r*2+1, c+1, e, v));
}

int getMin(int st[], int r, int s, int e, int bs, int be)
{
	if(e < bs || be < s) return INF;
	if(bs <= s && e <= be) return st[r];
	int c = (s+e)/2;
	return min(getMin(st, r*2, s, c, bs, be), 
		getMin(st, r*2+1, c+1, e, bs, be));
}

int main()
{
	int n, m;
	scanf("%d", &n);
	int *v = new int[n];
	for(int i = 0; i < n; i++) scanf("%d", v+i);
	int *st = new int[n*4];
	init(st, 1, 0, n-1, v);
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", getMin(st, 1, 0, n-1, a-1, b-1));
	}
}
