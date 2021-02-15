#include <iostream>
using namespace std;
int n, m, moving[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char map[1002][1002], visited[1002][1002];
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + moving[i][0], nx = x + moving[i][1];
        if (map[ny][nx] && !visited[ny][nx]) dfs(ny, nx);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= m; ++x) scanf("%1d", &map[y][x]);
    
    int ans = 0;
    for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= m; ++x)
            // 방문하지 않은 땅이 있다면 DFS로 섬을 탐색함
            if (map[y][x] && !visited[y][x]) dfs(y, x), ans++;
    
    printf("%d\n", ans);
}
