#include <cstdio>
void swap(int* arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
} 
void quickSort(int* arr, int start, int end) {
    if (start >= end) return;    // boundary condition.
    
    int p = start, l = start + 1, r = end;
    while (l <= r) {
        while (l <= end && arr[l] <= arr[p]) ++l;
        while (r > start && arr[r] >= arr[p]) --r;
        (l > r) ? swap(arr, r, p) : swap(arr, r, l);
    }
    quickSort(arr, start, r - 1);
    quickSort(arr, r + 1, end);
}
int main() {
    int N;
    scanf("%d", &N);
    
    int* arr = new int[N];
    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    
    quickSort(arr, 0, N - 1);
    
    for (int i = 0; i < 15; ++i) printf("%d\n", arr[i]);
    
    delete[] arr;    
}
