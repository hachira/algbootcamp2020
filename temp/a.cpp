#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	char *s = "*****************************************************";
	for(int i = 1; i <= n; i++)
		printf("%.*s\n", i, s);
}
