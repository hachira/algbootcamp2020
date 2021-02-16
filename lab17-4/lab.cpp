#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 파라메트릭 서치
int n, m, t[100000];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int maxTime = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        maxTime = max(maxTime, t[i]);
    }
    int left = 1, right = maxTime * m, ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2, sum = 0;
        for (int i = 0; i < n; ++i) sum += mid / t[i];
        if (sum < m) left = mid + 1;
        else ans = mid, right = mid - 1;
    }
    cout << ans << '\n';
}
