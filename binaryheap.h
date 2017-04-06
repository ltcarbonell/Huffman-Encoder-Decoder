#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;

/*
 * BinaryHeap Class Declaration
 */
class BinaryHeap
{
    private:
        vector <int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyup(int index);
        void heapifydown(int index);
    public:
        BinaryHeap(){}
        void Insert(int element);
        void deleteMin();
        int ExtractMin();
        int Size();
};
