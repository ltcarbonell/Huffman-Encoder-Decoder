#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "binaryheap.h"
#include "4wayheap.h"
#include "pairingheap.h"

using namespace std;

clock_t start_time;

void build_tree_using_binary_heap(vector<int> freq_table) {
    BinaryHeap h;
    for (size_t i = 0; i < freq_table.size(); i++) {
        h.Insert(freq_table.at(i));
    }

}

void build_tree_using_4way_heap(vector<int> freq_table) {
    FourWayHeap h;
    for (size_t i = 0; i < freq_table.size(); i++) {
        h.insert(freq_table.at(i));
    }

}

void build_tree_using_pairing_heap(vector<int> freq_table) {
    PairingHeap h;
    for (size_t i = 0; i < freq_table.size(); i++) {
        h.Insert(freq_table.at(i));
    }

}

vector<int> parseFile(string filename) {
    ifstream infile(filename);
    int value;
    vector<int> result;
    while (infile >> value) {
        result.push_back(value);
    }
    return result;
}

int main(int argc, char const *argv[]) {
    string filename = "sample2/sample_input_large.txt";

    vector<int> freq_table = parseFile(filename);

    // binary heap
    start_time = clock();
    for(int i = 0; i < 10; i++) {
        //run 10 times on given data set
        build_tree_using_binary_heap(freq_table);
    }
    cout << "Average time using binary heap (microsecond):  " << (clock() - start_time)/10 << endl;

    // 4-way heap
    start_time = clock();
    for(int i = 0; i < 10; i++) {
        //run 10 times on given data set
        build_tree_using_4way_heap(freq_table);
    }
    cout << "Average time using 4-way heap (microsecond):  " << (clock() - start_time)/10 << endl;

    // pairing heap
    start_time = clock();
    for(int i = 0; i < 10; i++) {
        //run 10 times on given data set
        build_tree_using_pairing_heap(freq_table);
    }
    cout << "Average time using pairing heap (microsecond):  " << (clock() - start_time)/10 << endl;

    return 0;
}
