// C++ program for Huffman Coding
#include <fstream>
using namespace std;

// A Huffman tree node
struct MinHeapNode
{
	int data;			 // One of the input characters
	unsigned freq;			 // Frequency of the character
	MinHeapNode *left, *right; // Left and right child

	MinHeapNode(int data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of two heap nodes (needed in min heap)
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{
    ofstream myfile;
    myfile.open ("code_table.txt", ios::out | ios::app);
	if (!root) {
        return;
    }

	if (root->data != '$') {
        myfile << root->data << " " << str << "\n";
        // cout << root->data << " " << str << "\n";
    }


	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
    myfile.close();
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(vector<int> data, vector<int> freq)
{
	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	for (int i = 0; i < data.size(); ++i) {
        minHeap.push(new MinHeapNode(data.at(i), freq.at(i)));
        cout << "Data " << data.at(i) << " - Freq " << freq.at(i) << endl;
    }

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1)
	{
		// Extract the two minimum freq items from min heap
		left = minHeap.top();
		minHeap.pop();
        // printCodes(left, "left");

		right = minHeap.top();
		minHeap.pop();
        // printCodes(right, "right");

		// Create a new internal node with frequency equal to the
		// sum of the two nodes frequencies. Make the two extracted
		// node as left and right children of this new node. Add
		// this node to the min heap
		// '$' is a special value for internal nodes, not used
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	// Print Huffman codes using the Huffman tree built above
    ofstream myfile;
    myfile.open("code_table.txt", ios::out | ios::trunc);
    myfile.close();
	printCodes(minHeap.top(), "");
}
