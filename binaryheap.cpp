#include "binaryheap.h"

int BinaryHeap::Size() {
    return heap.size();
}

void BinaryHeap::Insert(int element) {
    heap.push_back(element);
    heapifyup(heap.size() -1);
}

void BinaryHeap::deleteMin() {
    if (heap.size() == 0) {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap.at(0) = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
}

int BinaryHeap::ExtractMin() {
    if (heap.size() == 0) {
        return -1;
    }
    else
        return heap.front();
}

int BinaryHeap::left(int parent) {
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}

int BinaryHeap::right(int parent) {
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}

int BinaryHeap::parent(int child) {
    int p = (child - 1)/2;
    if (child == 0)
        return -1;
    else
        return p;
}

void BinaryHeap::heapifyup(int in) {
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in]) {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(parent(in));
    }
}

void BinaryHeap::heapifydown(int in) {

    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
       child = child1;
    }
    if (child > 0 && heap[in] > heap[child]) {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        heapifydown(child);
    }
}
