#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "4wayheap.h"
using namespace std;

/*
 *  EncodeTree Class Prototype
 */

class EncodeTree {
private:
    HuffmanNode* root;
    // vector<HuffmanNode*> array;
    FourWayHeap heap;
    string outFileName;
    map<int,string> code_table;

    HuffmanNode* buildTree(vector<HuffmanNode*> inputArray);
    void printSubTree(HuffmanNode* root, string output);
    void updateCodeTable();
    void updateSubTree(HuffmanNode* root, string output);
public:
    HuffmanNode* combineElements(HuffmanNode* first, HuffmanNode* second);
    void writeCodeTableToOutfile();
    string getBinPathTo(int key);

    EncodeTree(vector<HuffmanNode*> inputArray, string outFileName);
};
