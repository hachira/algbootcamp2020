#include <iostream>
using namespace std;
int n, k, r;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    // Step 1. Initialize and input.
    int c, p, chon[n + 1][n + 1];
    fill(&chon[0][0], &chon[n][n], 1e9);
    for (int i = 1; i <= n; ++i) chon[i][i] = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> c >> p;
        chon[c][p] = chon[p][c] = 1;
    }
    // Step 2. Floyd-Warshall O(n^3)
    // Because n is small & start vertex is not defined.
    for (int m = 1; m <= n; ++m)
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                if (chon[u][m] != 1e9 && chon[m][v] != 1e9)    
                    chon[u][v] = min(chon[u][v], chon[u][m] + chon[m][v]);
    // Step 3. Get answers.
    cin >> r;
    int x, y;
    for (int i = 0; i < r; ++i) {
        cin >> x >> y;
        cout << ((chon[x][y] != 1e9) ? chon[x][y] : -1) << '\n';
    }
}
