#include "pairingheap.h"


PairingHeap::PairingHeap() {
    root = NULL;
}

PairNode *PairingHeap::Insert(int &x) {
    PairNode *newNode = new PairNode(x);
    if (root == NULL)
        root = newNode;
    else
        compareAndLink(root, newNode);
    return newNode;
}

int &PairingHeap::findMin() {
    return root->element;
}

void PairingHeap::deleteMin() {
    PairNode *oldRoot = root;
    if (root->leftChild == NULL)
        root = NULL;
    else
        root = combineSiblings(root->leftChild);
    delete oldRoot;
}

bool PairingHeap::isEmpty() {
    return root == NULL;
}

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
