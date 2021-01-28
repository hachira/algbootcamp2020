#include <stdio.h>
#include <memory.h>
#include <queue>

void dfs(int r, int n, int adjMat[][100], char *visited)
{
	printf("%d\n", r+1);
	visited[r] = 1;
	for(int i = 0; i < n; i++)
	{
		if(adjMat[r][i] == 1 && !visited[i]) dfs(i, n, adjMat, visited);
	}
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int adjMat[n][100];
	memset(adjMat, 0, sizeof(int)*n*n);

	for(int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adjMat[a-1][b-1] = 1;
		adjMat[b-1][a-1] = 1;
	}

	char visited[n];
	printf("DFS\n");
	memset(visited, 0, n);
	dfs(0, n, adjMat, visited);

	printf("BFS\n");
	memset(visited, 0, n);
	std::queue<int> que;
	que.push(0);
	visited[0] = 1;
	while(!que.empty())
	{
		int r = que.front(); que.pop();
		printf("%d\n", r+1);
		for(int i = 0; i < n; i++)
		{
			if(adjMat[r][i] == 1 && !visited[i])
			{
				que.push(i);
				visited[i] = 1;
			}
		}
	}
}
