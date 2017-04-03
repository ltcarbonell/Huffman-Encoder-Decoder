#include <iostream>
#include <string>
#include "HuffmanDecoder.h"
using namespace std;

void DecodeTree::addLeafAt(int value, string binaryLocation) {
    Node *curr;
    curr = root;
    for (int i = 0; i < binaryLocation.length(); i++) {
        if (binaryLocation.at(i) == '0') {
            if (curr->left == NULL) {
                Node* newNode = new (struct Node);
                curr->left = newNode;
            }
            curr = curr->left;
        }
        else if (binaryLocation.at(i) == '1') {
            if (curr->right == NULL) {
                Node* newNode = new (struct Node);
                curr->right = newNode;
            }
            curr = curr->right;
        }
    }
    curr->value = value;
    curr->isLeaf = true;
}

int DecodeTree::getAt(string binaryLocation) {
    Node *curr;
    curr = root;
    // cout << "Get " << binaryLocation << endl;
    for (int i = 0; i < binaryLocation.length(); i++) {
        if (curr == NULL) {
            // cout << "Invalid leaf location" << endl;
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
        // cout << "Invalid leaf location" << endl;
        return -1;
    }
}

Node* DecodeTree::getRoot() {
    return root;
}
