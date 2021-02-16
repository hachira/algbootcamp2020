#include <iostream>
using namespace std;
int n, ans, a[100001], tmp[100001];
void merge(int left, int mid, int right) {
    int leftCur = left, rightCur = mid + 1, cur = left;
    while (leftCur <= mid && rightCur <= right) {
        if (a[leftCur] <= a[rightCur]) tmp[cur++] = a[leftCur++];
        else {
		  	  tmp[cur++] = a[rightCur++];
		  	  ans += mid+1-leftCur;
		  }
        // 해당 숫자의 원래 위치와 정렬됐을 때의 위치 사이 거리가 곧 swap 횟수.
    }
    // 아랫 부분은 merge sort랑 똑같음.
    while (leftCur <= mid) {
        tmp[cur++] = a[leftCur++];
    } 
	 while (rightCur <= right) {
        tmp[cur++] = a[rightCur++];
    }
    for (int i = left; i <= right; ++i) a[i] = tmp[i];
}
void getSwapCnt(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    getSwapCnt(left, mid);
    getSwapCnt(mid + 1, right);
    merge(left, mid, right);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    getSwapCnt(0, n - 1);
    cout << ans << '\n';
}
