#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "HuffmanNode.h"
using namespace std;

/*
 * FourWayHeap Class Declaration
 */
class FourWayHeap {
    private:
        vector<HuffmanNode*> heap;
        void buildHeap();
        int smallestChild(int hole);
        int parent(int i);
        int kthChild(int i, int k);
        void heapifyDown(int hole);
        void heapifyUp(int hole);
    public:
        FourWayHeap(){}
        bool isEmpty();
        void insert(HuffmanNode* x);
        HuffmanNode* popMin();
        HuffmanNode* Delete(int hole);
        int heapSize();
};
