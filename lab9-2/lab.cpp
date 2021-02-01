#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
const float INF = 1e9;

float distance(int v1[], int v2[])
{
	float xx = v1[0] - v2[0], yy = v1[1] - v2[1];
	return (float)sqrt(xx*xx + yy*yy);
}

int main()
{
	int n, k;
	scanf("%d", &n);
	int v[n+1][2];
	for(int i = 1; i <= n; i++) scanf("%d%d", &v[i][0], &v[i][1]);
	scanf("%d", &k);
	std::vector<int> adjList[n+1];
	for(int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adjList[a].push_back(b);
	}
	std::priority_queue<std::pair<float, int>, 
		std::vector<std::pair<float, int>>, 
		std::greater<std::pair<float, int>>> pq;
	int start, end;
	scanf("%d%d", &start, &end);
	float values[n+1]; bool visited[n+1];
	for(int i = 1; i <= n; i++) { values[i] = INF; visited[i] = false; }
	values[start] = 0;
	pq.push({ 0, start });
	while( !pq.empty() ) 
	{
		auto r = pq.top(); pq.pop();
		if(r.second == end) break;
		if(visited[r.second]) continue;
		visited[r.second] = true;
		for(auto c : adjList[r.second])
		{
			float t = values[r.second] + distance(v[r.second], v[c]);
			if(values[c] > t)
			{
				values[c] = t;
				pq.push({ t+distance(v[c], v[end]), c });
			}
		}
	}
	printf("%.2f\n", values[end]);
}
