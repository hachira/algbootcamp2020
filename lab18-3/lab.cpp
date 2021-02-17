#include <cstdio>
#define MOD 1000000007
typedef unsigned long long ull;
ull gcd(ull a, ull b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void mult(ull* lhs, ull* rhs) {
    ull temp[4] = {0, };
    temp[0] = (lhs[0]*rhs[0]) % MOD + (lhs[1]*rhs[2]) % MOD;
    temp[1] = (lhs[0]*rhs[1]) % MOD + (lhs[1]*rhs[3]) % MOD;
    temp[2] = (lhs[2]*rhs[0]) % MOD + (lhs[3]*rhs[2]) % MOD;
    temp[3] = (lhs[2]*rhs[1]) % MOD + (lhs[3]*rhs[3]) % MOD;
    for (int i = 0; i < 4; ++i) lhs[i] = temp[i]%MOD;
}
ull getFibo(ull n) {
    if (n == 1) return n;
    
    ull a[4] = {1, 1, 1, 0}, b[4] = {1, 0, 0, 1};
    for (; n > 0; n >>= 1) {
        if (n % 2 == 1) mult(b, a);
        mult(a, a);
    }
    return b[2];
}
// 행렬곱 피보나치
// gcd(fibo(n), fibo(m))==fibo(gcd(n, m)) 이용
int main() {
    ull n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", getFibo(gcd(n, m)));
}
