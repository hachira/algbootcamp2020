#include <cstdio>

int fibo(int n) {
    if (n == 0 || n == 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibo(n));
}
