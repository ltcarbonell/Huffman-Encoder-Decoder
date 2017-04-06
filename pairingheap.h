#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/*
 *  PairNode Class Prototype
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
 *  PairingHeap Class Prototype
 */
 
class PairingHeap {
    private:
        PairNode *root;
        void compareAndLink(PairNode * &first, PairNode *second);
        PairNode *combineSiblings(PairNode *firstSibling);
    public:
        PairingHeap();
        bool isEmpty();
        int &findMin();
        PairNode *Insert(int &x);
        void deleteMin();
};
