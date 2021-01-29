#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int parent[100001]; 
static vector<pair<int, pair<int, int> > > edges;
int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}
void unionParent(int a, int b) {
    a = findParent(a), b = findParent(b);
    parent[b] = a;
}
int main(void) {
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= v; i++) parent[i] = i;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({cost, {a, b}});
    }
    sort(edges.begin(), edges.end());
    
    int result = 0, finished = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first, b = edges[i].second.second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
				if(++finished == v-1) break;
        }
    }
    cout << result << '\n';
}
