#include <stdio.h>

int main()
{
	double f[2] = { 0, 1 };

	for(int i = 2; i <= 100; i+=2)
	{
		f[0] += f[1];
		f[1] += f[0];
		printf("%.3lf\n", f[1]/f[0]);
	}
}
