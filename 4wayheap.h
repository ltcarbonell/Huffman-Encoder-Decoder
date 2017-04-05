#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "HuffmanNode.h"
using namespace std;
/*
 * Class Declaration
 */
class FourWayHeap
{
    private:
        vector<HuffmanNode*> heap;
        void buildHeap();
        int smallestChild(int hole);
        int parent(int i);
        int kthChild(int i, int k);
        void percolateDown(int hole);
        void percolateUp(int hole);
    public:
        FourWayHeap(){}
        bool isEmpty();
        void insert(HuffmanNode* x);
        HuffmanNode* popMin();
        HuffmanNode* Delete(int hole);
        void printHeap();
        int heapSize();
};
