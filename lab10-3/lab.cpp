#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int N, M, maze[1001][1001], ans[1001][1001][2];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs() {
    queue<tuple<int, int, int> > q;
    q.push({1, 1, 0});    // start at (1, 1), Hammer is available.
    ans[1][1][0] = 1;
    
    while (!q.empty()) {
        int cy, cx, hammer;
        tie(cy, cx, hammer) = q.front(); q.pop();        
        if (cy == N && cx == M) return;
    
        for (int i = 0; i < 4; ++i) {
            int ny = cy + d[i][0], nx = cx + d[i][1];
            if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
            // Case 1. Empty space
            if (maze[ny][nx] == 0 && ans[ny][nx][hammer] == 0) {
                ans[ny][nx][hammer] = ans[cy][cx][hammer] + 1;
                q.push({ny, nx, hammer});
            }
            // Case 2. Wall, Can we brake it with the hammer?
            if (maze[ny][nx] == 1 && hammer == 0 && ans[ny][nx][hammer + 1] == 0) {
                ans[ny][nx][hammer + 1] = ans[cy][cx][hammer] + 1;
                q.push({ny, nx, hammer + 1});
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int y = 1; y <= N; ++y)
        for (int x = 1; x <= M; ++x)
            scanf("%1d", &maze[y][x]);
    
    bfs();
    
    if (ans[N][M][0] != 0 && ans[N][M][1] != 0)
        printf("%d\n", min(ans[N][M][0], ans[N][M][1]));
    else if (ans[N][M][0] != 0)
        printf("%d\n", ans[N][M][0]);
    else if (ans[N][M][1] != 0)
        printf("%d\n", ans[N][M][1]);
    else
        printf("-1\n");
}
