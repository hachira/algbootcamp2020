#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define	INF	1000000000
static bool visited[10001];
static vector<pair<int, int>> graph[10001];
static int values[10001];
int doPrim(int startVertex) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    // Initialize pq
	 values[1] = 0;
	 pq.push({0, 1});
    int ret = 0;
    while (!pq.empty()) {
        int dist = pq.top().first, curNode = pq.top().second;
        pq.pop();
        if (!visited[curNode]) {
            visited[curNode] = true;    // Leave a visit mark.
            ret += dist;
            for (auto v : graph[curNode]) {
                if (!visited[v.first] && values[v.first] > v.second) {
						pq.push({v.second, v.first});
						values[v.first] = v.second;
				    }
			   }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int v1, v2, w;    // start, end, weight
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
	 for(int i = 1; i <= n; i++) values[i] = INF;
    int answer = doPrim(1);
    cout << answer << '\n';
}
