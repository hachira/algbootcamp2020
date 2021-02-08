#include <iostream>
using namespace std;
template<typename T> class PriorityQueue {
	T *heap;
	int size;
	void _push(int child);
	void _pop(int parent);
public:
    PriorityQueue(int n = 0) { 
        size = 0;
        heap = new T[n + 1];
    }
    void push(T val) { 
        heap[++size] = val;
        _push(size);    // heapify
    }
    T pop() {
        if (size == 0) return -1;
        T ret = heap[1];
        heap[1] = heap[size--];
        _pop(1);        // heapify
        return ret;
    }
    ~PriorityQueue() { 
        delete[] heap;
    }
};
template <typename T>
void PriorityQueue<T>::_push(int child) {
    if (child == 1) return;
    int parent = child / 2;
    if (heap[parent] > heap[child]) {
        swap(heap[parent], heap[child]);
        _push(child / 2);
    }
}
template <typename T>
void PriorityQueue<T>::_pop(int parent) {
    int left, right;
    left = (parent * 2 <= size) ? parent * 2 : -1;
    right = (left == -1) ? -1 : left + 1;
    
    if (left == -1 && right == -1) return;
    
    int child;
    if (right == -1) child = left;
    else child = (heap[left] < heap[right]) ? left : right;
    
    if (heap[parent] > heap[child]) {
        swap(heap[parent], heap[child]);
        _pop(child);
    }
}
int main() {
    int n;
    cin >> n;
    
    PriorityQueue<int> pq(n);
    
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'G') cout << pq.pop() << '\n';
        else if (op == 'P'){
            int num;
            cin >> num;
            pq.push(num);
        }
    }    
}
