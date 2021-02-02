#include <cstdio>
#include <cmath>
// Bruteforce(2^N^2)  or Backtracking(N!)
// col[i] means queen is at (col[i], i)
static int N = 0, answer = 0, col[15];
bool check(int depth) {
    for (int i = 0; i < depth; ++i)
        // 1) No same row.  2) No diagonal positions.
        if (col[depth] == col[i] || abs(col[depth] - col[i]) == depth - i) return false;
    return true;
}
void nqueen(int depth) {
    if (depth == N) { answer++; return;    }    // we found correct case!
    for (int i = 0; i < N; ++i) {
        col[depth] = i;        // Put queen (y, x) = (depth, i)
        if (check(depth)) nqueen(depth + 1);
    }
}
int main() {
    scanf("%d", &N);
    nqueen(0);
    printf("%d\n", answer);
}
