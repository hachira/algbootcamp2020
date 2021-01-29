#include <iostream>
#include <vector>
#include <queue>
#define INF 2e9
using namespace std;
static vector<int> dist(100001);
static vector<pair<int, int>> graph[100001];
void dijkstra(int startV) {
    // Use min heap for djikstra.
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, startV});    // weight, vertex number
    dist[startV] = 0;
    
    while (!pq.empty()) {
        int cd = pq.top().first, cv = pq.top().second;
        pq.pop();
        if (dist[cv] < cd) continue;    // No necessary to process.
        for (const auto& edge : graph[cv]) {
            int nd = cd + edge.first, nv = edge.second;
            if (dist[nv] > nd) {        // then, we need to update dist value!
                dist[nv] = nd;
                pq.push({nd, nv});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, s;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {    // input k edges.
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});    // weight, end vertex.
    }
    cin >> s;
    
    fill_n(begin(dist), n + 1, INF);    // initialization
    dijkstra(s);
    
    cout << '\n';
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}
