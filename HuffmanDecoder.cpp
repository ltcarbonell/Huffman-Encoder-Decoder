#include <iostream>
#include <string>
#include "HuffmanDecoder.h"
using namespace std;

void DecodeTree::addLeafAt(int value, string binaryLocation) {
    HuffmanNode *curr;
    curr = root;
    for (int i = 0; i < binaryLocation.length(); i++) {
        if (binaryLocation.at(i) == '0') {
            if (curr->left == NULL) {
                HuffmanNode* newNode = new (struct HuffmanNode);
                curr->left = newNode;
            }
            curr = curr->left;
        }
        else if (binaryLocation.at(i) == '1') {
            if (curr->right == NULL) {
                HuffmanNode* newNode = new (struct HuffmanNode);
                curr->right = newNode;
            }
            curr = curr->right;
        }
    }
    curr->value = value;
    curr->isLeaf = true;
}

int DecodeTree::getAt(string binaryLocation) {
    HuffmanNode *curr;
    curr = root;
    for (int i = 0; i < binaryLocation.length(); i++) {
        if (curr == NULL) {
            return -1;
        }
        else if (binaryLocation.at(i) == '0') {
            curr = curr->left;
        }
        else if (binaryLocation.at(i) == '1') {
            curr = curr->right;
        }
    }
    if (curr->isLeaf == true) {
        return curr->value;
    }
    else {
        return -1;
    }
}

HuffmanNode* DecodeTree::getRoot() {
    return root;
}
