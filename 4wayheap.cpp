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
* Function to inset element
*/
void FourWayHeap::insert(int x) {
    int hole = heap.size();
    heap.push_back(x);
    percolateUp(hole);
}

/*
* Function to find least element
*/
int FourWayHeap::findMin() {
    if (isEmpty()) {
        cout<<"Array Underflow"<<endl;
        return 0;
    }
    return heap.at(0);
}
/*
* Function to delete element at an index
*/
int FourWayHeap::Delete(int hole) {
    if (isEmpty()) {
        cout<<"Array Underflow"<<endl;
        return 0;
    }
    int keyItem = heap.at(hole);
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
    int child;
    int tmp = heap.at(hole);
    for ( ; kthChild(hole, 1) < heap.size(); hole = child) {
        child = smallestChild( hole );
        if (heap.at(child) < tmp) {
            heap.at(hole) = heap.at(child);

        }
        else {
            break;

        }
    }
    heap.at(hole) = tmp;
}

/*
* Function to get smallest child from all valid indices
*/
int FourWayHeap::smallestChild(int hole) {
    int bestChildYet = kthChild(hole, 1);
    int k = 2;
    int candidateChild = kthChild(hole, k);
    while ((k <= 4) && (candidateChild < heap.size())) {
        if (heap.at(candidateChild) < heap.at(bestChildYet))
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
    int tmp = heap.at(hole);
    for (; hole > 0 && tmp < heap[parent(hole)]; hole = parent(hole))
    heap.at(hole) = heap.at(parent(hole));
    heap.at(hole) = tmp;
}

/*
* Function to print heap
*/
void FourWayHeap::printHeap() {
    cout<<"\nHeap = ";
    for (int i = 0; i < heap.size(); i++)
    cout<<heap.at(i)<<"   ";
    cout<<endl;
}
