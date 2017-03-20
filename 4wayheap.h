#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;
/*
 * Class Declaration
 */
class FourWayHeap
{
    private:
        vector<int> heap;
        void buildHeap();
        int smallestChild(int hole);
        int parent(int i);
        int kthChild(int i, int k);
        void percolateDown(int hole);
        void percolateUp(int hole);
    public:
        FourWayHeap(){}
        bool isEmpty();
        void insert(int x);
        int findMin();
        int Delete(int hole);
        void printHeap();
};
