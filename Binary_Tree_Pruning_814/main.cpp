#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool TreeContainOne(TreeNode *root) {
    if (NULL == root) return false;
    return root->val == 1 || TreeContainOne(root->left) || TreeContainOne(root->right);
}

TreeNode *pruneTree(TreeNode *root) {
    if (NULL == root) return root;
    if (!TreeContainOne(root)) root = NULL;
    if (!TreeContainOne(root->left)) root->left = NULL;
    else {
        pruneTree(root->left);
    }
    if (!TreeContainOne(root->right)) root->right = NULL;
    else {
        pruneTree(root->right);
    }
    return root;
}

int main() {
    return 0;
}

