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

void inOrder(TreeNode *root, vector<int> &v) {
    if (!root) return;
    inOrder(root->left, v);
    v.push_back(root->val);
    inOrder(root->right, v);
}

int kthSmallest(TreeNode *root, int k) {
    vector<int> v;
    inOrder(root, v);
    return v[k - 1];
}

int main() {
    return 0;
}

