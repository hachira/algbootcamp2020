#include <iostream>
#include <vector>
using namespace std;
using matrix = vector<vector<long long>>;

// n의 최대값이 20억이므로 overflow와 시간복잡도를 유의한다.
// Overflow를 막기 위해 'long long' type을 사용한다.
// 시간제한 2초를 만족하기 위해 DP를 이용한 O(n) 방법 대신 O(log(n)) 해결법을 사용한다.
// 수학적으로 행렬곱을 이용한 피보나치 수열 구하는 법은 O(log(n))으로 해결됨이 증명됐다.
// 또는 n번째 피보나치 수를 구하는 일반항을 사용하는 방법도 유효하다.
matrix operator *(const matrix &a, const matrix &b) {
    // 두 행렬 a와 b의 곱을 연산자 오버로딩으로 구현한다.
	int n = a.size();
	matrix c(n, vector<long long>(n));
	
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				c[i][j] += ((a[i][k] * b[k][j]) % 1000000009);
		}
	}
	return c;
}

int getFibo(int n) {
    matrix a = {{1, 1}, {1, 0}};
	matrix b = {{1, 0}, {0, 1}};

	if (n < 2) return n;
	else {
		for (; n > 0; n /= 2) {
            // n이 홀수인 경우 b를 a로 갱신하고 행렬 a는 제곱한다.
			if (n % 2 != 0) b = b * a;
			a = a * a;
		}
		return b[0][1] % 1000000009;
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    cout << getFibo(n) << '\n';    
}
