#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int moving[4][2] {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void bfs(vector<vector<int> >& maze, vector<vector<int> >& answer, int N, int M) {
    queue<pair<int, int> > q;
    q.push({1, 1});
    answer[1][1] = 1;
    
    while (!q.empty()) {
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = cy + moving[i][0], nx = cx + moving[i][1];
            // if (ny, nx) is possible and not visited
            if ((1 <= ny && ny <= N) && (1 <= nx && nx <= M)) {
                if (maze[ny][nx] == 1 && answer[ny][nx] == 0) {
                    q.push({ny, nx});
                    answer[ny][nx] = answer[cy][cx] + 1;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    
    vector<vector<int> > maze(N + 1, vector<int>(M + 1));
    vector<vector<int> > answer(N + 1, vector<int>(M + 1));
    for (int y = 1; y <= N; ++y) {
        string str;
        cin >> str;
        for (int x = 1; x <= M; ++x)
            maze[y][x] = str[x - 1] - '0';
    }
    bfs(maze, answer, N, M);
    cout << answer[N][M] << '\n';
}
