#include <stdio.h>
#include <time.h>
int main()
{
	long t = clock();
	//	Module for time measure
	t = (clock() - t)*1000/CLOCKS_PER_SEC;
	printf("Elapsed time : %ldms\n", t);
}
