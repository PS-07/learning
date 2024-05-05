#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // time complexity = O(log n)
    void heapifyUp(int idx) {
        // compare and swap node with parent until it fits
        int parent = (idx - 1) / 2;
        while (idx > 0) {
            if (heap[parent] > heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    // time complexity = O(log n)
    void heapifyDown(int idx) {
        // compare and swap node with its largest child until it fits
        int size = heap.size();
        while (idx < size) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;
            if (left < size && heap[left] < heap[smallest]) { smallest = left; }
            if (right < size && heap[right] < heap[smallest]) { smallest = right; }
            if (idx != smallest) {
                swap(heap[idx], heap[smallest]);
                idx = smallest;
            } else {
                break;
            }
        }
        
    }

public:
    MinHeap() {}

    // time complexity = O(log n)
    void insert(int value) {
        // insert at the end and then heapify upwards
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // time complexity = O(log n)
    void deleteMin() {
        // delete root node, replace it with last node and then heapify down
        if (heap.empty()) { return; }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

     // time complexity = O(1)
    int getMin() { return heap.empty() ? -1 : heap[0]; }

    bool empty() { return heap.empty(); }

    void printHeap() {
        cout<<"Heap: ";
        for (int value : heap) {
            cout<<value<<" ";
        }
        cout<<endl;
    }

    // time complexity = O(n * log n)
    static vector<int> heapSort(vector<int> arr) {
        // build min heap
        MinHeap minHeap;
        for (int value : arr) {
            minHeap.insert(value);
        }

        // remove min elements to get sorted result
        vector<int> sorted;
        while (!minHeap.empty()) {
            sorted.push_back(minHeap.getMin());
            minHeap.deleteMin();
        }
        return sorted;
    }
};

int main() {
    MinHeap heap;

    vector<int> nums = {5, 10, 3, 8, 7};
    for (int n : nums) { heap.insert(n); }
    
    heap.printHeap();
    cout<<"min = "<<heap.getMin()<<endl;

    heap.deleteMin();
    heap.deleteMin();
    cout<<"min = "<<heap.getMin()<<endl;

    vector<int> arr = {0, 5, 2, 8, 1, 4, 9, 7, 3, 6};
    vector<int> sorted = MinHeap::heapSort(arr);

    cout<<"Sorted array: ";
    for (int num : sorted) {
        cout<<num<<" ";
    }
    cout<<endl;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n : arr) { pq.push(n); }

    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}
