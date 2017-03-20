#include <iostream>
#include <string>
#include <fstream>
#include "HuffmanDecoder.h"

using namespace std;

int main(int argc, char const *argv[]) {
    DecodeTree DT = DecodeTree();
    int a;
    string b;
    ifstream ct("code_table.txt", ios::in);
    cout << "Building Decode Tree" << endl;
    while (ct >> a >> b) {
        DT.addLeafAt(a, b);
    }
    // cout << DT.getAt("111") << "<-" << endl;

    ofstream myfile;
    myfile.open("decoded.txt", ios::out);
    cout << "Decoding binary file" << endl;
    ifstream f("encoded.bin", ios::binary | ios::in);
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
