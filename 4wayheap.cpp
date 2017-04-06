#include <iostream>
#include <cstring>
#include <cstdlib>
#include "4wayheap.h"
using namespace std;

bool FourWayHeap::isEmpty() {
    return heap.size() == 0;
}

int FourWayHeap::heapSize() {
    return heap.size();
}

int FourWayHeap::parent(int i) {
    return (i - 1) / 4;
}

int FourWayHeap::kthChild(int i, int k) {
    return 4 * i + k;
}

void FourWayHeap::insert(HuffmanNode* x) {
    int hole = heap.size();
    heap.push_back(x);
    percolateUp(hole);
}

HuffmanNode* FourWayHeap::popMin() {
    if (isEmpty()) {
        cout<<"Array Underflow"<<endl;
        return 0;
    }
    return delete(0);
}

HuffmanNode* FourWayHeap::Delete(int hole) {
    if (isEmpty()) {
        cout<<"Array Underflow"<<endl;
        return 0;
    }
    HuffmanNode* keyItem = heap.at(hole);
    heap.at(hole) = heap.back();
    heap.pop_back();
    percolateDown(hole);
    return keyItem;
}

void FourWayHeap::buildHeap() {
    for (int i = heap.size() - 1 ; i >= 0; i--)
    percolateDown(i);
}

void FourWayHeap::percolateDown(int hole) {
    if (!isEmpty()) {
        int childIndex;
        HuffmanNode* tmp = heap.at(hole);
        while (kthChild(hole, 1) < heap.size()) {
            childIndex = smallestChild( hole );
            if (heap.at(childIndex)->value < tmp->value) {
                heap.at(hole) = heap.at(childIndex);
            }
            else {
                break;
            }
            hole = childIndex;
        }
        heap.at(hole) = tmp;
    }
}

int FourWayHeap::smallestChild(int hole) {
    int bestChildYet = kthChild(hole, 1);
    int k = 2;
    int candidateChild = kthChild(hole, k);
    while ((k <= 4) && (candidateChild < heap.size())) {
        if (heap.at(candidateChild)->value < heap.at(bestChildYet)->value)
        bestChildYet = candidateChild;
        k++;
        candidateChild = kthChild(hole, k);
    }
    return bestChildYet;
}

void FourWayHeap::percolateUp(int hole) {
    HuffmanNode* tmp = heap.at(hole);
    while (hole > 0 && tmp->value < heap.at(parent(hole))->value) {
        heap.at(hole) = heap.at(parent(hole));
        hole = parent(hole);
    }
    heap.at(hole) = tmp;
}
