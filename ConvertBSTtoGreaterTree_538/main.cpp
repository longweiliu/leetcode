#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *convertBSTHelper(TreeNode *root, int sum) {
    if (root) {
        convertBSTHelper(root->right, sum);
        sum += root->val;
        root->val = sum;
        convertBSTHelper(root->left, sum);
    }
    return root;
}

TreeNode *convertBST(TreeNode *root) {
    root = convertBSTHelper(root, 0);
    return root;
}

int main() {
    return 0;
}

