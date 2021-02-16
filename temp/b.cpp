#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
	int *p = new int[100000000];

	for(int i = 0; i < 100000000; i++) p[i] = rand()%1000;
	std::sort(p, p+100000000);
	for(int i = 0; i < 10; i++) printf("%d ", p[i]);
}
