#include <iostream>
#include <vector>
#define INF 2e9
using namespace std;
typedef struct Edge {
    int s, e, w;
    Edge(int s = 0, int e = 0, int w = 0) : s(s), e(e), w(w) {}
}Edge;
// Bellman-Ford Time: O(V*E) 
bool bellmanFord(const vector<Edge>& graph, vector<int>& dist, int startV) {
    dist[startV] = 0;
    int n = dist.size() - 1;
    
	 bool dirty = false;
    for (int i = 0; i < n; ++i) {
	 	  dirty = false;
        for (int j = 0; j < graph.size(); ++j) {
            int sv = graph[j].s, ev = graph[j].e, cost = graph[j].w;
            // if 'sv' is visited and should be updated,
            if (dist[sv] != INF && dist[ev] > dist[sv] + cost) {
					dist[ev] = dist[sv] + cost;    
					dirty = true;
				}
        }
		  if(!dirty) break;
    }
    return !dirty;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, s;
    cin >> n >> k;
    
    vector<int> dist(n + 1, INF);
    vector<Edge> graph(n + 1);
    
    int a, b, w;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b >> w;
        graph.push_back(Edge(a, b, w));
    }
    cin >> s;
    if (bellmanFord(graph, dist, s)) {
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) cout << "No Path\n";
            else cout << dist[i] << '\n';
        }
            
    }
    else cout << "There is negative cycle in the graph.\n";
}
