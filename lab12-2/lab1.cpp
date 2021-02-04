#include <iostream>
#include <vector>
using namespace std;
using matrix = vector<vector<long long>>;
matrix a = {{1, 1}, {1, 0}};
matrix b = {{1, 0}, {0, 1}};
matrix operator * (const matrix &a, const matrix &b) {
    matrix c(2, vector<long long>(2));
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++)
                c[i][j] += ((a[i][k] * b[k][j]) % 1000000009);
				c[i][j] %= 1000000009;
        }
    }
    return c;
}
matrix getFibo(int n) {
    matrix c = a;
    if (n > 1) {
        c = getFibo(n / 2);
        c = c * c;
        if (n % 2 != 0) c = c * a;
    }
    return c;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    matrix answer = getFibo(n);
    cout << answer[0][1] << '\n';    
}
