#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
    deque<TreeNode *> dq;
    vector<vector<int>> res;
    if (!root)
        return res;
    dq.push_back(root);
    while (!dq.empty()) {
        vector<int> v;
        vector<TreeNode *> nodes;
        while (!dq.empty()) {
            TreeNode *node = dq.front();
            nodes.push_back(node);
            v.push_back(node->val);
            dq.pop_front();
        }
        res.push_back(v);
        for (auto node : nodes) {
            if (node->left) dq.push_back(node->left);
            if (node->right) dq.push_back(node->right);
        }
    }
    return res;
}

int main() {
    return 0;
}

