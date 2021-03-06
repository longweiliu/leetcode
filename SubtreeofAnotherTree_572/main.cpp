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

bool isSameTree(TreeNode *s, TreeNode *t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(TreeNode *s, TreeNode *t) {
    if (!s) return false;
    if (isSameTree(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}


int main() {

    return 0;
}

