#include <stdio.h>
int gcd(int a, int b)
{
	int r = 0;
	for(int i=1;i<=a;i++)
		if(a%i==0 && b%i==0) r = i;
	return r;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", gcd(a,b));
}
