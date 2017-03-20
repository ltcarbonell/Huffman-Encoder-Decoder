#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
/*
 * Node Class Declaration
 */
class PairNode {
    public:
        int element;
        PairNode *leftChild;
        PairNode *nextSibling;
        PairNode *prev;
        PairNode(int element) {
            this->element = element;
            leftChild = NULL;
            nextSibling = NULL;
            prev = NULL;
        }
};

/*
 * Class Declaration
 */
class PairingHeap
{
    private:
        PairNode *root;
        void compareAndLink(PairNode * &first, PairNode *second);
        PairNode *combineSiblings(PairNode *firstSibling);
        //  void reclaimMemory(PairNode *t);
    public:
        PairingHeap();
        // ~PairingHeap();
        bool isEmpty();
        int &findMin();
        PairNode *Insert(int &x);
        void deleteMin();
        // void makeEmpty();
};
