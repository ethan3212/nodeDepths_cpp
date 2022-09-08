#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// helper structure
struct Level {
    BinaryTree *root;
    int depth;
};

// O(n) time | O(depth) space
int nodeDepthsStruct(BinaryTree *root) {
    int sumOfDepths = 0;
    vector<Level> stack = {{root, 0}};
    while(!stack.empty()) {// O(n) time
        BinaryTree *node = stack.back().root;
        int depth = stack.back().depth;
        stack.pop_back();
        if(node == nullptr) {
            continue;
        }
        sumOfDepths += depth;
        stack.push_back(Level{node->left, depth + 1});// O(log(n)) time
        stack.push_back(Level{node->right, depth + 1});// O(log(n)) time
    }
    return sumOfDepths;
}

// O(n) time | O(depth) space
int nodeDepthsSimplest(BinaryTree *node, int depth = 0) {
    if(node == nullptr) {
        return 0;
    }
    return depth + nodeDepthsSimplest(node->right, depth + 1) + nodeDepthsSimplest(node->left, depth + 1);// O(n) time | O(depth) space
}

int main() {
    BinaryTree *root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->left = new BinaryTree(4);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    root->left->right = new BinaryTree(5);
    root->right = new BinaryTree(3);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);

    cout << nodeDepthsSimplest(root) << endl;
    cout << nodeDepthsStruct(root) << endl;

    return 0;
}
