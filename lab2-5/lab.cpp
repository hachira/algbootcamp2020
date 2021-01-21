//	에라토스테네스의 체(Eratosthenes Sieve)를 이용해서
//	소수의 개수를 구해보자.
#include <stdio.h>
#include <memory.h>

int pi(int n)
{
	//	귀찮은 애들은 처리하도록 하자.
	if(n < 2) return 0;
	if(n == 2) return 1;

	int pn = 1, p;
	char *v = new char[n+1];
	memset(v, 0, n+1);
	for(p=3; p*p <= n; p += 2)
	{
		if(v[p]) continue;
		pn++;
		for(int j = p*p; j <= n; j+=p) v[j] = 1;
	}
	for( ; p <= n; p += 2) if(v[p]==0) pn++;
	return pn;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", pi(n));
}
