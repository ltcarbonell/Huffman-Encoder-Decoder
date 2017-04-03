#include <iostream>
#include <string>
using namespace std;

/*
 *  Node Struct Prototype
 */

struct Node {
    struct Node *right = NULL;
    struct Node *left = NULL;
    int value;
    bool isLeaf = false;
};

/*
 *  DecodeTree Class Prototype
 */


class DecodeTree {
private:
    Node* root;
public:
    Node* getRoot();
    void addLeafAt(int value, string binaryLocation);
    int getAt(string binaryLocation);

    DecodeTree() {
        root = new (struct Node);
    }
};
