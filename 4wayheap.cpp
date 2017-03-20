/*
*  C++ Program to Implement 4-way-Heap
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "4wayheap.h"
using namespace std;

/*
* Function to check if heap is empty
*/
bool FourWayHeap::isEmpty() {
    return heap.size() == 0;
}

/*
* Function to return heap size
*/
int FourWayHeap::heapSize() {
    return heap.size();
}

/*
* Function to  get index parent of i
*/
int FourWayHeap::parent(int i) {
    return (i - 1) / 4;
}

/*
* Function to get index of k th child of i
*/
int FourWayHeap::kthChild(int i, int k) {
    return 4 * i + k;
}

/*
* Function to insert element
*/
void FourWayHeap::insert(HuffmanNode* x) {
    // cout << "Inserting..." << endl;
    int hole = heap.size();
    // cout << "Push" << endl;
    heap.push_back(x);
    // cout << "Percolate hole " << hole << endl;
    percolateUp(hole);
    // cout << "Percolate finish" << endl;
    // printHeap();
}

/*
* Function to find least element
*/
HuffmanNode* FourWayHeap::popMin() {
    if (isEmpty()) {
        cout<<"Array Underflow"<<endl;
        return 0;
    }
    return Delete(0);
}
/*
* Function to delete element at an index
*/
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

/*
* Function to build heap
*/
void FourWayHeap::buildHeap() {
    for (int i = heap.size() - 1 ; i >= 0; i--)
    percolateDown(i);
}

/*
* Function percolateDown
*/
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

/*
* Function to get smallest child from all valid indices
*/
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

/*
* Function percolateUp
*/
void FourWayHeap::percolateUp(int hole) {
    HuffmanNode* tmp = heap.at(hole);
    // cout << "Hole " << hole << endl;
    // cout << "child Value " << tmp->value << endl;
    // cout << "parent Value " << heap.at(parent(hole))->value << endl;
    while (hole > 0 && tmp->value < heap.at(parent(hole))->value) {
        // cout << "Hole " << hole << endl;
        // cout << "child Value " << tmp->value << endl;
        // cout << "parent Value " << heap.at(parent(hole))->value << endl;
        heap.at(hole) = heap.at(parent(hole));
        hole = parent(hole);
    }
    // cout << "set temp" << endl;
    heap.at(hole) = tmp;
    // cout << "finish temp" << endl;

}

/*
* Function to print heap
*/
void FourWayHeap::printHeap() {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap.at(i)->key << ", " <<heap.at(i)->value<<"   ";
    }
    cout<<endl;
}
