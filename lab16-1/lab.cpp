#include <iostream>
using namespace std;
int n, a[100000], dp[100000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // LIS(최장 증가 부분수열)의 아주 약간 변형 문제
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (a[i] < a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
    cout << n - ans << '\n';
}
