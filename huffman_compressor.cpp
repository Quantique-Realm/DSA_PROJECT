#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <bitset>

// Define a structure for Huffman Tree nodes
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparison object to order the heap
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to generate the Huffman codes
void generateCodes(Node* root, std::string code, std::unordered_map<char, std::string>& huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Function to build the Huffman Tree
Node* buildHuffmanTree(std::unordered_map<char, int>& frequency) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;

    for (auto pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() != 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        int sum = left->freq + right->freq;
        Node* newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    return minHeap.top();
}

// Function to compress the input file
void compressFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath, std::ios::in);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file!" << std::endl;
        return;
    }

    std::unordered_map<char, int> frequency;
    char ch;
    while (inputFile.get(ch)) {
        frequency[ch]++;
    }

    Node* root = buildHuffmanTree(frequency);

    std::unordered_map<char, std::string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file!" << std::endl;
        return;
    }

    std::string encodedString = "";
    while (inputFile.get(ch)) {
        encodedString += huffmanCode[ch];
    }

    int extraBits = 8 - (encodedString.size() % 8);
    for (int i = 0; i < extraBits; ++i) {
        encodedString += "0";
    }

    outputFile.put(extraBits);

    for (size_t i = 0; i < encodedString.size(); i += 8) {
        std::bitset<8> byte(encodedString.substr(i, 8));
        outputFile.put(byte.to_ulong());
    }

    inputFile.close();
    outputFile.close();
    std::cout << "File compressed successfully!" << std::endl;
}

// Main function to accept command-line arguments
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file_path> <output_file_path>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string compressedFilePath = argv[2];

    compressFile(inputFilePath, compressedFilePath);

    return 0;
}
