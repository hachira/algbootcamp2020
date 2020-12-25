#include <iostream>
#include <vector>
using namespace std;

/*
빠르게 소수를 구하기 위해 '에라토스테네스 체'를 사용한다.
2부터 n 까지의 자연수의 배수는 모두 소수가 될 수 없으므로 false 처리한다.
마지막 반복문까지 true로 남은 수는 소수이고 그 개수를 카운트한다.
*/
int getPrimeCount(int n) {
    vector<bool> prime(n + 1, true);
    int ret = n;
    for (int i = 2; i <= n; ++i)
        if (prime[i])
            // 1이 아닌 자연수의 배수는 모두 소수가 될 수 없으므로 false 처리한다.
            for (int j = i * 2; j <= n; j += i)
                if (prime[j]) {
                    prime[j] = false;	
                    ret--;				// 개수를 감산한다.
                }
    return ret - 1;						// 1은 소수가 아니므로 제외한다. 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    cout << getPrimeCount(n) << '\n';
}
