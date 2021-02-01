#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > graph(n + 1, vector<int>());
    vector<int> indegree(n + 1);
    
    for (int i = 0; i < k; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        indegree[v2]++;
    }
    // topology sort 
    vector<int> answer;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0) q.push(i);
    
    while (!q.empty()) {
        int cv = q.front(); 
        q.pop();
        answer.push_back(cv);
        for (const int& nv : graph[cv]) {
            if (--indegree[nv] == 0) q.push(nv);
        }
    }
    if (answer.size() != n) cout << "Wrong Graph!\n";
    else {
        for (const int& ele : answer) cout << ele << ' ';
        cout << '\n';
    }
}
