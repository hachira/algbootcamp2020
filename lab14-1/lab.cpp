#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> arr, int n) {
    int minIdx;
    for (int i = 0; i < n-1; ++i) {
        minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[minIdx] > arr[j]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
    printf("Selection Sort >>> ");
    for (int i = 0; i < 15; ++i) printf("%d ", arr[i]);
    printf("\n");
}
void insertionSort(vector<int> arr, int n) {
    for (int i = 1; i < n; ++i) {
        int j, key = arr[i];
        for (j = i - 1; j >= 0; --j) {
            if (arr[j] > key) arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = key;
    }
    printf("Insertion Sort >>> ");
    for (int i = 0; i < 15; ++i) printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    
    //selectionSort(arr, n);
    insertionSort(arr, n);
}
