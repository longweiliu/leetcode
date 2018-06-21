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

bool isValidBSTHelper(TreeNode *root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val >= maxVal || root->val <= minVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root) {
    return isValidBSTHelper(root, LONG_LONG_MIN, LONG_LONG_MAX);
}

//bool isValidBST(TreeNode *root) {
//    vector<int> v = inorderTraversal(root);
//    for (int i = 1; i < v.size(); ++i) {
//        if (v[i] <= v[i - 1]) {
//            return false;
//        }
//    }
//    return true;
//}

int main() {

    return 0;
}

