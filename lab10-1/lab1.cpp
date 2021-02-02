#include <cstdio>
#include <cmath>
// Bruteforce(2^N^2)  or Backtracking(N!)
// col[i] means queen is at (col[i], i)
static int N = 0, answer = 0, col[15];
static char d0[15], d1[32], d2[32];
bool check(int depth) {
	if(d0[col[depth]]) return false;
	if(d1[col[depth]+depth]) return false;
	if(d2[col[depth]+N-depth]) return false;
	return true;
}
void nqueen(int depth) {
    if (depth == N) { answer++; return;    }    // we found correct case!
    for (int i = 0; i < N; ++i) {
        col[depth] = i;        // Put queen (y, x) = (depth, i)
        if (check(depth)) {
		   d0[i] = 1; d1[i+depth] = 1; d2[i-depth+N] = 1;
		  	nqueen(depth + 1);
		   d0[i] = 0; d1[i+depth] = 0; d2[i-depth+N] = 0;
		}
    }
}
int main() {
    scanf("%d", &N);
    nqueen(0);
    printf("%d\n", answer);
}
