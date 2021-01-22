#include <stdio.h>

int main()
{
	int fact[6] = { 1, 1, 2, 6, 6, 3 };
	int n;
	scanf("%d", &n);
	if( n >= 6 ) printf("9");
	else printf("%d", fact[n]);
}
