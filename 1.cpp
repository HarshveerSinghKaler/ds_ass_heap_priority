#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void max_heapify(vector<int>& heap, int i, int heap_size) {
    int l = 2*i;
    int r = 2*i + 1;

    int largest = i;

    if(l <= heap_size && heap[l] > heap[largest]) largest = l;

    if(r <= heap_size && heap[r] > heap[largest]) largest = r;

    if(largest != i) {
        swap(heap[i], heap[largest]);
        max_heapify(heap, largest, heap_size);
    }
}

void min_heapify(vector<int>& heap, int i, int heap_size) {
    int l = 2*i;
    int r = 2*i + 1;
    int smallest = i;

    if(l <= heap_size && heap[l] < heap[smallest]) smallest = l;
    if(r <= heap_size && heap[r] < heap[smallest]) smallest = r;

    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        min_heapify(heap, smallest, heap_size);
    }
}

// increasing order
void heapSort(vector<int>& heap) {
    int heap_size = heap.size() - 1;
    
    for(int i=heap_size/2; i>=1; i--) {
        max_heapify(heap, i, heap_size);
    }

    while(heap_size >= 2) {
        swap(heap[1], heap[heap_size]);
        heap_size -= 1;
        max_heapify(heap, 1, heap_size);
    }
}

// decreasing order
void heapSortDec(vector<int>& heap) {
    int heap_size = heap.size() - 1;
    
    for(int i=heap_size/2; i>=1; i--) {
        min_heapify(heap, i, heap_size);
    }

    while(heap_size >= 2) {
        swap(heap[1], heap[heap_size]);
        heap_size -= 1;
        min_heapify(heap, 1, heap_size);
    }
}

int main() {
    vector<int> heap = {0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    for(int i=1; i<heap.size(); i++) cout<<heap[i]<<" ";

    heapSort(heap);

    cout<<endl;

    for(int i=1; i<heap.size(); i++) cout<<heap[i]<<" ";

    heapSortDec(heap);

    cout<<endl;

    for(int i=1; i<heap.size(); i++) cout<<heap[i]<<" ";

    return 0;
}