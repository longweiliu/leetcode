#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode *root) {
    deque<TreeNode *> d;
    d.push_back(root);
    while (!d.empty()) {
        TreeNode *node = d.front();
        d.pop_front();
        if (node->right) {
            d.push_back(node->right);
        }
        if (node->left) {
            d.push_back(node->left);
        }
    }
    return d.back()->val;
}

int main() {
    return 0;
}

