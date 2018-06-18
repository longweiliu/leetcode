#include <iostream>
#include <vector>
#include <algorithm>
#include<deque>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> largestValues(TreeNode *root) {
    vector<int> v;
    if (!root)
        return v;
    deque<TreeNode *> d;
    stack<TreeNode *> s;
    d.push_back(root);
    while (!d.empty()) {
        while (!d.empty()) {
            s.push(d.back());
            d.pop_back();
        }
        int max = INT_MIN;
        while (!s.empty()) {
            TreeNode *node = s.top();
            if (node->left) {
                d.push_back(node->left);
            }
            if (node->right) {
                d.push_back(node->right);
            }
            if (node->val > max) {
                max = node->val;
            }
            s.pop();
        }
        v.push_back(max);
    }
    return v;
}

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *three_5 = new TreeNode(5);
    TreeNode *three_3 = new TreeNode(3);
    TreeNode *three_9 = new TreeNode(9);
    TreeNode *two_3 = new TreeNode(3);
    TreeNode *two_2 = new TreeNode(2);
    root->left = two_3;
    root->right = two_2;
    two_3->left = three_5;
    two_3->right = three_3;
    two_2->right = three_9;
    vector<int> v = largestValues(root);
    for (auto num : v) {
        cout << num << ' ';
    }
    return 0;
}

