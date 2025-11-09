#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
    vector<int> heap;

    void max_heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            max_heapify(largest);
        }
    }

public:
    MaxPriorityQueue() {
        heap.push_back(-1);
    }

    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        while (i > 1 && heap[i / 2] < heap[i]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    void pop() {
        if (heap.size() <= 1) {
            cout << "Queue is empty!\n";
            return;
        }
        heap[1] = heap.back();
        heap.pop_back();
        max_heapify(1);
    }

    int top() {
        if (heap.size() <= 1) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[1];
    }

    bool empty() {
        return heap.size() <= 1;
    }
};

class MinPriorityQueue {
    vector<int> heap;

    void min_heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            min_heapify(smallest);
        }
    }

public:
    MinPriorityQueue() {
        heap.push_back(-1);
    }

    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        while (i > 1 && heap[i / 2] > heap[i]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    void pop() {
        if (heap.size() <= 1) {
            cout << "Queue is empty!\n";
            return;
        }
        heap[1] = heap.back();
        heap.pop_back();
        min_heapify(1);
    }

    int top() {
        if (heap.size() <= 1) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[1];
    }

    bool empty() {
        return heap.size() <= 1;
    }
};
