#include <iostream>
#include <string>
#include <fstream>
#include "HuffmanDecoder.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cerr << "Invalid nummber of arguments" << endl;
        return 1;
    }
    string encoded_filename = argv[1];
    string code_table_filename = argv[2];


    DecodeTree DT = DecodeTree();
    int a;
    string b;
    ifstream ct(code_table_filename, ios::in);
    cout << "Building Decode Tree" << endl;
    while (ct >> a >> b) {
        DT.addLeafAt(a, b);
    }

    ofstream myfile;
    myfile.open("decoded.txt", ios::out);
    cout << "Decoding binary file" << endl;
    ifstream f(encoded_filename, ios::binary | ios::in);
    char c;
    string resultChunk;
    while (f.get(c)) {
        for (int i = 7; i >= 0; i--) {// or (int i = 0; i < 8; i++)  if you want reverse bit order in bytes
            int d = (c >> i) & 1;
            resultChunk.append(to_string(d));
            if (DT.getAt(resultChunk) != -1) {
                myfile << DT.getAt(resultChunk) << endl;
                resultChunk = "";
            }
        }
    }
    myfile.close();
    return 0;
}
