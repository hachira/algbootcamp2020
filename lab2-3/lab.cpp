#include <iostream>
#include <math.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n = 0;
    cin >> n;
    
    int answer = 0;
	int i;
	int s = (int)sqrt(n);
    for (i = 1; i < s; ++i) {
        if (n % i == 0) {
            answer+=2;
        }
    }
    if (i * i == n) answer++;
    cout << answer << '\n';
}
