#include <stdio.h>
void inverse(char a[])
{
	int n=0;
	while(a[n]) n++;
	for(int i = 0; i < n/2; i++)
	{
		int t = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = t;
	}
}
int main()
{
	char a[128], b[128];
	scanf("%s%s", a, b);
	int c = 0, i;
	inverse(a);
	inverse(b);
	for(i = 0; a[i] && b[i]; i++)
	{
		c += a[i] + b[i] - '0'*2;
		a[i] = c%10 + '0';
		c /= 10;
	}
	if(a[i])
	{
		while(a[i]) { c += a[i] - '0'; a[i++] = c%10 + '0'; c /= 10; }
	}
	else
	{
		while(b[i]) { c += b[i] - '0'; a[i++] = c%10 + '0'; c /= 10; }
	}
	if(c) a[i++] = c + '0';
	for( i--; i >= 0; i--) putchar(a[i]); putchar('\n');
}
