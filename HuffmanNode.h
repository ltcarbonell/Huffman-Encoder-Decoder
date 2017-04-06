#include <iostream>
#include <string>
using namespace std;

/*
 *  HuffmanNode Struct Prototype
 */
 
struct HuffmanNode {
    struct HuffmanNode *right = NULL;
    struct HuffmanNode *left = NULL;
    int value = 0;
    int key = -1;
    bool isLeaf = false;
};
