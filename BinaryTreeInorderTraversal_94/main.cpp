#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root, vector<int> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

// iterative
vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *curr = root;
    vector<int> v;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        v.push_back(curr->val);
        curr = curr->right;
    }
    return v;
}

// recursive
//vector<int> inorderTraversal(TreeNode *root) {
//    vector<int> v;
//    inorder(root, v);
//    return v;
//}

int main() {

    return 0;
}

