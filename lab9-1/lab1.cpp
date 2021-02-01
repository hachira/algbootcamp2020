<iostream>
#include <vector>
#define INF 1e9
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) graph[i][i] = 0;
    for (int i = 1; i <= k; ++i) {
        int s, f, w;    cin >> s >> f >> w;
        if (graph[s][f] < w) continue;
        graph[s][f] = w;
    }
    for (int m = 1; m <= n; ++m) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (graph[u][m] == INF || graph[m][v] == INF) continue;
                graph[u][v] = min(graph[u][v], graph[u][m] + graph[m][v]);
            }
        }
    }
    // [Important] Check negative cycle
    for (int u = 1; u <= n; ++u) {
        if (graph[u][u] < 0) {
            cout << "Negative cycle is detected!\n";
            return 0;
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (graph[u][v] == INF) printf("INF ");
            else printf("%3d", graph[u][v]);
        }
        puts("");
    }
}
