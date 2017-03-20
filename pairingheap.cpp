/*
 * C++ Program to Implement Pairing Heap
 */
#include "pairingheap.h"


PairingHeap::PairingHeap() {
    root = NULL;
}

/*
 * Destroy the leftist heap.
 */
// PairingHeap::~PairingHeap()
// {
//     makeEmpty();
// }

/*
 * Insert item x into the priority queue, maintaining heap order.
 * Return a pointer to the node containing the new item.
 */
PairNode *PairingHeap::Insert(int &x) {
    PairNode *newNode = new PairNode(x);
    if (root == NULL)
        root = newNode;
    else
        compareAndLink(root, newNode);
    return newNode;
}

/*
 * Find the smallest item in the priority queue.
 * Return the smallest item, or throw Underflow if empty.
 */
int &PairingHeap::findMin() {
    return root->element;
}

/*
 * Remove the smallest item from the priority queue.
 * Throws Underflow if empty.
 */
void PairingHeap::deleteMin() {
    PairNode *oldRoot = root;
    if (root->leftChild == NULL)
        root = NULL;
    else
        root = combineSiblings(root->leftChild);
    delete oldRoot;
}

/*
 * Test if the priority queue is logically empty.
 * Returns true if empty, false otherwise.
 */
bool PairingHeap::isEmpty() {
    return root == NULL;
}

/*
 * Make the priority queue logically empty.
 */

// void PairingHeap::makeEmpty()
// {
//     reclaimMemory(root);
//     root = NULL;
// }

/*
 * Internal method to make the tree empty.
 */
// void PairingHeap::reclaimMemory(PairNode * t)
// {
//     if (t != NULL)
//     {
//         reclaimMemory(t->leftChild);
//         reclaimMemory(t->nextSibling);
//         delete t;
//     }
// }

/*
 * Internal method that is the basic operation to maintain order.
 * Links first and second together to satisfy heap order.
 * first is root of tree 1, which may not be NULL.
 *    first->nextSibling MUST be NULL on entry.
 * second is root of tree 2, which may be NULL.
 * first becomes the result of the tree merge.
 */
void PairingHeap::compareAndLink(PairNode * &first, PairNode *second) {
    if (second == NULL)
        return;
    if (second->element < first->element)
    {
        second->prev = first->prev;
        first->prev = second;
        first->nextSibling = second->leftChild;
        if (first->nextSibling != NULL)
            first->nextSibling->prev = first;
        second->leftChild = first;
        first = second;
    }
    else
    {
        second->prev = first;
        first->nextSibling = second->nextSibling;
        if (first->nextSibling != NULL)
            first->nextSibling->prev = first;
        second->nextSibling = first->leftChild;
        if (second->nextSibling != NULL)
            second->nextSibling->prev = second;
        first->leftChild = second;
    }
}

/*
 * Internal method that implements two-pass merging.
 * firstSibling the root of the conglomerate;
 *     assumed not NULL.
 */
PairNode *PairingHeap::combineSiblings(PairNode *firstSibling) {
    if (firstSibling->nextSibling == NULL)
        return firstSibling;
    static vector<PairNode *> treeArray(5);
    int numSiblings = 0;
    for (; firstSibling != NULL; numSiblings++)
    {
        if (numSiblings == treeArray.size())
            treeArray.resize(numSiblings * 2);
        treeArray[numSiblings] = firstSibling;
        firstSibling->prev->nextSibling = NULL;
        firstSibling = firstSibling->nextSibling;
    }
    if (numSiblings == treeArray.size())
        treeArray.resize(numSiblings + 1);
    treeArray[numSiblings] = NULL;
    int i = 0;
    for (; i + 1 < numSiblings; i += 2)
        compareAndLink(treeArray[i], treeArray[i + 1]);
    int j = i - 2;
    if (j == numSiblings - 3)
        compareAndLink (treeArray[j], treeArray[j + 2]);
    for (; j >= 2; j -= 2)
        compareAndLink(treeArray[j - 2], treeArray[j] );
    return treeArray[0];
}
