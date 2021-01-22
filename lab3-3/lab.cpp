#include <stdio.h>

int fib(int n)
{
	int f[2] = { 0, 1 };
	for(int i = 2; i <= n; i += 2)
	{
		f[0] += f[1];
		f[1] += f[0];
	}
	return f[n%2];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fib(n));
}
