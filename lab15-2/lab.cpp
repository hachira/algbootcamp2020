#include <cstdio>
void swap(int* arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
int getPivot(int* arr, int s, int e) {
    int p = s, l = s + 1, r = e;
    while (l <= r) {
        while (l <= e && arr[l] <= arr[p]) ++l;
        while (r > s && arr[r] >= arr[p]) --r;
        (l > r) ? swap(arr, r, p) : swap(arr, r, l);
    }
    return r;    // pivot's index number.
}
int find(int* arr, int s, int e, int k) {
    int p = getPivot(arr, s, e);
    if (p == k) return arr[p];
    if (p > k) return find(arr, s, p - 1, k);
    return find(arr, p + 1, e, k);
}
int main() {
    int N;
    scanf("%d", &N);
    
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    
    int K;
    scanf("%d", &K);
    
    printf("%d\n", find(arr, 0, N - 1, K-1));
    delete[] arr;
}
