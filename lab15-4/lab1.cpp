#include <stdio.h>
int phi(int n)
{
	int phi = 1;
	if(n%2==0)
	{
		n/=2;
		while(n%2 == 0) { n/=2; phi*=2; }
	}
	for(int p = 3; p*p <= n; p += 2)
	{
		if(n%p) continue;
		n /= p; phi *= p-1;
		while(n%p==0) { n/=p; phi*=p; }
	}
	return (n>1)?(n-1)*phi:phi;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", phi(n));
}
