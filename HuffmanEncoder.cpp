#include <iostream>
#include <string>
#include <fstream>
#include "HuffmanEncoder.h"
using namespace std;

EncodeTree::EncodeTree(vector<HuffmanNode*> inputArray, string outFileName) {
    this->heap = FourWayHeap();
    this->root = buildTree(inputArray);
    this->outFileName = outFileName;
    this->code_table = map<int, string>();
    updateCodeTable();
}

HuffmanNode* EncodeTree::combineElements(HuffmanNode* first, HuffmanNode* second) {
    HuffmanNode* newRoot = new (struct HuffmanNode);
    newRoot->left = first;
    newRoot->right = second;
    newRoot->value = first->value + second->value;
    newRoot->isLeaf = false;
    newRoot->key = -1;
    return newRoot;
}

HuffmanNode* EncodeTree::buildTree(vector<HuffmanNode*> inputArray) {
    for (size_t i = 0; i < inputArray.size(); i++) {
        this->heap.insert(inputArray.at(i));
    }
    cout << "Finished Inserting" << endl;


    HuffmanNode* result;
    HuffmanNode* firstElem;
    HuffmanNode* secondElem;
    cout << "Combining elements" << endl;
    while (this->heap.heapSize() > 1) {
        firstElem = this->heap.popMin();
        secondElem = this->heap.popMin();
        result = combineElements(firstElem, secondElem);
        this->heap.insert(result);
    }
    return result;
}

void EncodeTree::writeCodeTableToOutfile() {
    ofstream myfile;
    myfile.open(this->outFileName, ios::out);
    for( map<int,string>::iterator ii=this->code_table.begin(); ii!=this->code_table.end(); ++ii) {
        myfile << (*ii).first << " " << (*ii).second << endl;
    }
    myfile.close();
}

string EncodeTree::getBinPathTo(int key) {
    return this->code_table[key];
}

void EncodeTree::updateCodeTable() {
    updateSubTree(this->root, "");
}

void EncodeTree::updateSubTree(HuffmanNode* root, string output) {
    if (root == NULL) {
        return;
    }
    else if (root->isLeaf) {
        this->code_table[root->key] = output;
    }
    else {
        updateSubTree(root->left, output + "0");
        updateSubTree(root->right, output + "1");
    }
}
