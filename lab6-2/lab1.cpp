#include <stdio.h>
#include <vector>

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	std::vector<int> adjList[n];

	for(int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adjList[a-1].push_back(b);
		adjList[b-1].push_back(a);
	}

	for(int i = 0; i < n; i++)
	{
		printf("%d : ", i+1);
		for(auto k : adjList[i])
			printf("%d ", k);
		putchar('\n');
	}
}
