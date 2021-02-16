#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 중복없는 10개 수의 내림차순 조합은 (2^10 - 1)개임.
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<long long> a;
    for (int i = 1; i < (1 << 10); ++i) {        // i는 1~1023까지 증가,
        long long decreaseNum = 0; 
        for (int num = 9; num >= 0; num--) { 
            if (i & (1<<num)) decreaseNum = 10 * decreaseNum + num;
        }
        a.push_back(decreaseNum);
    }
    sort(begin(a), end(a));    // 정렬
    int n;
    cin >> n;
    cout << ((n > 1022) ? -1 : a[n]) << '\n';
}
