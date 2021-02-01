#include <stdio.h>
#define	INF	1e9

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int d[n+1][n+1];
	for(int u = 1; u <= n; u++)
		for(int v = 1; v <= n; v++) d[u][v] = (u!=v)*INF;
	for(int i = 0; i < k; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		d[a][b] = w;
	}
	for(int m = 1; m <= n; m++)
	{
		for(int u = 1; u <= n; u++)
		{
			for(int v = 1; v <= n; v++)
			{
				if(d[u][m] == INF || d[m][v] == INF) continue;
				if(d[u][v] > d[u][m] + d[m][v]) d[u][v] = d[u][m] + d[m][v];
			}
		}
	}
	for(int u = 1; u <= n; u++)
	{
		for(int v = 1; v <= n; v++)
		{
			if(d[u][v] == INF) printf("INF ");
			else printf("%3d ", d[u][v]);
		}
		putchar('\n');
	}
}
