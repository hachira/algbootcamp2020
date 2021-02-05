#include <stdio.h>

long long init(long long st[], int root, int v[], int s, int e)
{
	//	If leaf node, return v[s]
	if(s == e) return st[root] = v[s];
	//	divide
	int c = (s+e)/2;
	return st[root] = init(st, root*2, v, s, c) +
		init(st, root*2+1, v, c+1, e);
}

long long *build(int v[], int n)
{
	int ss = 1;
	while(ss < n) ss <<= 1;
	ss <<= 1;
	long long *st = new long long[ss];
	init(st, 1, v, 0, n-1);
	return st;
}

long long sum(long long st[], int root, int s, int e, int is, int ie)
{
	//	If (is, ie) exclude (s, e)
	if(ie < s || e < is) return 0;
	//	If (is, ie) include (s, e)
	if(is <= s && e <= ie) return st[root];
	int c = (s+e)/2;
	return sum(st, root*2, s, c, is, ie) +
		sum(st, root*2+1, c+1, e, is, ie);
}

long long update(long long st[], int root, int s, int e, int idx, int v)
{
	//	If idx is not in (s, e)
	if(idx < s || idx > e) return st[root];
	//	If leaf node, update leaf node value.
	if(s == e) return st[root] = v;
	int c = (s+e)/2;
	return st[root] = update(st, root*2, s, c, idx, v) +
		update(st, root*2+1, c+1, e, idx, v);
}

int main()
{
	int n, k;
	scanf("%d", &n);
	int v[n];
	for(int i = 0; i < n; i++) scanf("%d", v+i);

	//	segment tree build
	auto st = build(v, n);
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		char cmd[16]; int a, b;
		scanf("%s%d%d", cmd, &a, &b);
		if(cmd[0] == 's') printf("%lld\n", sum(st, 1, 0, n-1, a-1, b-1));
		else update(st, 1, 0, n-1, a-1, b);
	}
}
