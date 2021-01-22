#include <stdio.h>

int main()
{
	int k;
	scanf("%d", &k);
	for(int i = 0; i < 31; i++)
	{
		if( k&(1<<i) )
		{
			printf("%d", i+1);
			break;
		}
	}
}
