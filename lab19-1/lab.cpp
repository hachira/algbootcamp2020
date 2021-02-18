#include <stdio.h>
#include <math.h>

int main()
{
	int S, P;
	scanf("%d%d", &S, &P);
		
	if(S == P) { puts("1"); return 0; }
	int n = (int)(S*exp(-1.0));
	double maxValue = pow((double)S/n, n);
	double t = pow((double)S/(n+1), n+1);
	if(t > maxValue) { maxValue = t; n++; }

	if(P > maxValue) { puts("-1"); return 0; }

	//	Binary Search
	int left = 2, right = n;
	while(left < right)
	{
		int c = (left+right)/2;
		t = pow((double)S/c, c);
		if(P <= t) right = c;
		else left = c+1;
	}
	printf("%d\n", right);
}
