#include <stdio.h>
int gcd(int a, int b)
{
	while(b)
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", gcd(a,b));
}
