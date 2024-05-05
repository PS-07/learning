#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private: 
    vector<int> heap;

    // time complexity = O(log n)
    void heapifyUp(int idx) {
        // compare and swap node with parent until it fits
        while(idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] < heap[idx]) {
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
            int largest = idx;
            if (left < size && heap[left] > heap[largest]) { largest = left; }
            if (right < size && heap[right] > heap[largest]) { largest = right; }
            if (largest != idx) {
                swap(heap[idx], heap[largest]);
                idx = largest;
            } else {
                break;
            }
        }
    }

public: 
    MaxHeap() {}

    // time complexity = O(log n)
    void insert(int value) {
        // insert at the end and then heapify upwards
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // time complexity = O(log n)
    void deleteMax() {
        // delete root node, replace it with last node and then heapify down
        if (heap.empty()) { return; }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // time complexity = O(1)
    int getMax() { return heap.empty() ? -1 : heap[0]; }

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
        // build max heap
        MaxHeap maxHeap;
        for (int value : arr) {
            maxHeap.insert(value);
        }

        // remove max elements to get sorted result
        vector<int> sorted;
        while (!maxHeap.empty()) {
            sorted.push_back(maxHeap.getMax());
            maxHeap.deleteMax();
        }
        return sorted;
    }
};

int main() {
    MaxHeap heap;

    vector<int> nums = {5, 10, 3, 8, 7};
    for (int n : nums) { heap.insert(n); }
    
    heap.printHeap();
    cout<<"max = "<<heap.getMax()<<endl;

    heap.deleteMax();
    heap.deleteMax();
    cout<<"max = "<<heap.getMax()<<endl;

    vector<int> arr = {0, 5, 2, 8, 1, 4, 9, 7, 3, 6};
    vector<int> sorted = MaxHeap::heapSort(arr);

    cout<<"Sorted array: ";
    for (int num : sorted) {
        cout<<num<<" ";
    }
    cout<<endl;

    priority_queue<int> pq;
    for (int n : arr) { pq.push(n); }

    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}
