#include <cstdio>
int solve(int n) {
    if (n <= 2) return n;
    return solve(n - 2) + solve(n - 1);
    // use recurrence relation. (D(n) = D(n-2) + D(n-1))
}
int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", solve(n));
}
