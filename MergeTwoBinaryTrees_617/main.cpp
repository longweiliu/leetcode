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

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    auto *node = new TreeNode(0);
    if (t1 && t2) {
        node->val = t1->val + t2->val;
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
    } else if (t1) {
        node->val = t1->val;
        node->left = mergeTrees(t1->left, nullptr);
        node->right = mergeTrees(t1->right, nullptr);
    } else if (t2) {
        node->val = t2->val;
        node->left = mergeTrees(nullptr, t2->left);
        node->right = mergeTrees(nullptr, t2->right);
    } else {
        return nullptr;
    }
    return node;
}

int main() {
    return 0;
}

