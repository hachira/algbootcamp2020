#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool dp[2002][2002];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    cin >> str;
    int n = str.length();
    // Step 1. Every char is palindrome itself.
    for (int i = 0; i < n; ++i) dp[i][i] = true;
    // Step 2. Continuous char is palindrome.
    for (int i = 0; i < n - 1; ++i)
        if (str[i] == str[i + 1]) dp[i][i + 1] = true;
    // Step 3. Get palindrom DP.
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i < n - k; ++i) {
            int j = i + k;
            // Step 4. If [i] were same with [i + k]
            // and partial string between them (i+1 ~ i+k-1) was palindrom,
            if (str[i] == str[j] && dp[i + 1][j - 1]) dp[i][j] = true;
        }
    }
    // Step 4. Get how many more letters to put on the back.
    for (int i = 0; i < n; ++i) {
        if (dp[i][n - 1]) { // the first true value
            string reverseStr = str.substr(0, i);
            reverse(begin(reverseStr), end(reverseStr));
            str += reverseStr;
            break; 
        }
    }
    cout << str << '\n';
}
