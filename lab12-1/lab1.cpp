#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long getArea(const vector<long long>& hist, int start, int end) {
    // Boundary condition: 1) Start meets End, 2) there is only one block.
    if (start == end || hist.size() == 1) return hist[start];
    int mid = (start + end) / 2;
    // Step 1. Divide, Compare left part and right part
    long long tempArea = max(getArea(hist, start, mid), getArea(hist, mid + 1, end));
    
    // Step 2. Get height and area
    int left = mid, right = mid + 1;
    long long height = min(hist[left--], hist[right++]);
    long long area = max(tempArea, 2 * height);
    
    // Step 3. Get maximum area 
    while (start <= left || right <= end) {
        // process to right part
        if (right <= end && (left < start || hist[left] < hist[right])) 
            height = min(height, hist[right++]);
        // process to left part
        else 
            height = min(height, hist[left--]);
        area = max(area, height * (right - left -1));
    }
    return area;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> hist(n);
    for (int i = 0; i < n; ++i) cin >> hist[i];
    cout << getArea(hist, 0, n - 1) << '\n';
}
