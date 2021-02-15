#include <cstdio>
#include <cmath>
typedef unsigned long long ll;
int main() {
    ll n;
    scanf("%lld", &n);
    
    // 에라토스테네스의 체 + 오일러 파이 문제
    // n의 서로소 개수 = n * (1/p1) * (1/p2) *... (p1, p2..는 소인수)
    ll ans = n;
    for (ll i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) ans *= (1 - ((double)1 / (double)i));
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans *= (1 - ((double)1 / (double)n)); // n이 소수인 경우
    printf("%lld\n", ans);
}
