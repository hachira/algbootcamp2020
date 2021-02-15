#include <cstdio>

void swap(int* arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
void selectionSort(int* arr, int s, int e) {
    for (int i = s + 1; i <= e; ++i) {
        int j, key = arr[i];
        for (j = i - 1; j >= s; --j)
            if (arr[j] < key) arr[j + 1] = arr[j];
            else break;
        arr[j + 1] = key;
    }
}
int getPivot(int* arr, int s, int e) {
    int p = s, l = s + 1, r = e;
    while (l <= r) {
        while (l <= e && arr[l] >= arr[p]) ++l;
        while (r > s && arr[r] <= arr[p]) --r;
        (l > r) ? swap(arr, r, p) : swap(arr, r, l);
    }
    return r;
}
void quickSort(int* arr, int s, int e) {
    int size = e - s + 1;
    if (size > 15) {
        int p = getPivot(arr, s, e);
        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    } else {
        selectionSort(arr, s, e);
    }
}
int main() {
    int N;
    scanf("%d", &N);
    
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    
    int K;
    scanf("%d", &K);
    
    quickSort(arr, 0, N - 1);
    
    for (int i = 0; i < K; ++i) printf("%d ", arr[i]);
    printf("\n");
    
    delete[] arr; 
}
