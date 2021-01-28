#include <stdio.h>

void perm(char *str, int k, int n, int r, int v)
{
	if(k == r)
	{
		puts(str);
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(v & (1<<i)) continue;
		str[k] = i+'0';
		perm(str, k+1, n, r, v | (1<<i));
	}
}

int main()
{
	int n, r;
	scanf("%d%d", &n, &r);
	char str[r+1];
	str[r] = 0;
	perm(str, 0, n, r, 0);
}
