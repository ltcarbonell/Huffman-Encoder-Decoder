#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
// #include "4wayheap.h"
#include "HuffmanEncoder.h"

using namespace std;

#define MAX_SIZE 1000000

vector<int> parseFile(string filename) {
    ifstream infile(filename);
    int value;
    vector<int> result;
    while (infile >> value) {
        result.push_back(value);
    }
    return result;
}

char convertStringToBin(string binaryString) {
    char c = 0b0;
    for (int i = 0; i < 8; i++) {
        if (binaryString.at(7-i) == '1') {
            c |= 1 << i;
        }
        else if (binaryString.at(7-i) == '0') {
            c  &= ~(1 << i);
        }
    }

    return c;
}

int main(int argc, char const *argv[]) {
    // string filename = "sample1/sample_input_small.txt";
    // string filename = "sample1/sample_input_medium.txt";
    string filename = "sample2/sample_input_large.txt";

    cout << "Reading input file" << endl;
    int freq_table[MAX_SIZE] = {0};
    vector<int> input_table = parseFile(filename);
    for (size_t i = 0; i < input_table.size(); i++) {
        freq_table[input_table.at(i)] += 1;
    }

    vector<HuffmanNode*> inputArray;
    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (freq_table[i] > 0) {
            HuffmanNode* newNode = new (struct HuffmanNode);
            newNode->value = freq_table[i];
            newNode->key = i;
            newNode->isLeaf = true;
            inputArray.push_back(newNode);
        }
    }
    cout << "Building Huffman Encode Tree" << endl;
    EncodeTree ET = EncodeTree(inputArray, "code_table.txt");

    cout << "Write code_table.txt" << endl;
    // Print out code table to file
    ET.writeCodeTableToOutfile();

    // Create binary encoded file
    cout << "Writing to encoded binary file" << endl;
    ofstream myfile ("encoded.bin", ios::out | ios::binary);
    if (myfile.is_open()) {
        string binaryEncoding = "";
        for (size_t i = 0; i < input_table.size(); i++) {
            int key = input_table.at(i);
            binaryEncoding += ET.getBinPathTo(key);
            while (binaryEncoding.length() >= 8) {
                string byteSubstring = binaryEncoding.substr(0, 8);
                binaryEncoding.erase (0,8);
                char byteToWrite = convertStringToBin(byteSubstring);
                myfile.write( (char*)&byteToWrite, sizeof(char));
            }
        }
        // Write remaining bits that are less then 8 bits
        if (binaryEncoding.length() > 0) {
            for (size_t i = binaryEncoding.length(); i < 8; i++) {
                binaryEncoding += "0";
            }
            char byteToWrite = convertStringToBin(binaryEncoding);
            myfile.write( (char*)&byteToWrite, sizeof(char));
        }
    }
    myfile.close();


    return 0;
}
