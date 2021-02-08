#include <cstdio>
void merge(int* arr, int start, int mid, int end) {
    int *result = new int[end-start+1];
    int left = start, right = mid + 1, idx = 0;
    
    // Merge phase
    while (left <= mid && right <= end)
        result[idx++] = (arr[left] < arr[right]) ? arr[left++] : arr[right++];
    while (left <= mid) result[idx++] = arr[left++];
    while (right <= end) result[idx++] = arr[right++];
    
    // Overwrite phase
    idx--;
    while (idx >= 0) {
        arr[start + idx] = result[idx];
        idx--;
    }
}
void mergeSort(int* arr, int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);        // left side
        mergeSort(arr, mid + 1, end);    // right side
        merge(arr, start, mid, end);    // do merge
    }
}
int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < 15; ++i) printf("%d ", arr[i]);
    printf("\n");
}
