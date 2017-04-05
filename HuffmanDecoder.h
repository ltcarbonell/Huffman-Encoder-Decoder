#include <iostream>
#include <string>
#include "HuffmanNode.h"
using namespace std;

/*
 *  DecodeTree Class Prototype
 */

class DecodeTree {
private:
    HuffmanNode* root;
public:
    HuffmanNode* getRoot();
    void addLeafAt(int value, string binaryLocation);
    int getAt(string binaryLocation);

    DecodeTree() {
        root = new (struct HuffmanNode);
    }
};
