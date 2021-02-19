#include <stdio.h>
#include <unordered_map>
using namespace std;
#define	MOD	1000000000
void factorize(unordered_map<int, int> &map, int t)
{
	while(t%2 == 0) { map[2]++; t/=2; }
	for(int p = 3; p*p <= t; p += 2) while(t%p == 0) { map[p]++; t/=p; }
	if(t > 1) map[t]++;
}

int main()
{
	int n, m, t;
	scanf("%d", &n);
	unordered_map<int, int> a, b;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		factorize(a, t);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &t);
		factorize(b, t);
	}
	long long p = 1;
	for( auto k : a )
	{
		if(b.find(k.first) == b.end()) continue;
		int r = k.second;
		if( r > b[k.first] ) r = b[k.first];
		for(int i = 0; i < r; i++) p = (p*k.first)%MOD;
	}
	printf("%lld\n", p);
}
