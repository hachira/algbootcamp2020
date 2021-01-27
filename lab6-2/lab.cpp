#include <stdio.h>
#include <memory.h>

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int adjMat[n][n];
	memset(adjMat, 0, sizeof(int)*n*n);

	for(int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adjMat[a-1][b-1] = 1;
		adjMat[b-1][a-1] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", adjMat[i][j]);
		putchar('\n');
	}
}
