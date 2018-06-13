#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricHelp(TreeNode *left, TreeNode *right) {
    if (NULL == left || NULL == right) return left == right;
    if (left->val != right->val) return false;
    return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(left->right,right->left);
}

//recursion
bool isSymmetric(TreeNode *root) {
    return NULL == root || isSymmetricHelp(root->left,root->right);
}

//iteration
//bool isSymmetric(TreeNode *root) {
//    TreeNode *left, *right;
//    if (!root)
//        return true;
//
//    queue<TreeNode*> q1, q2;
//    q1.push(root->left);
//    q2.push(root->right);
//    while (!q1.empty() && !q2.empty()){
//        left = q1.front();
//        q1.pop();
//        right = q2.front();
//        q2.pop();
//        if (NULL == left && NULL == right)
//            continue;
//        if (NULL == left || NULL == right)
//            return false;
//        if (left->val != right->val)
//            return false;
//        q1.push(left->left);
//        q1.push(left->right);
//        q2.push(right->right);
//        q2.push(right->left);
//    }
//    return true;
//}

int main() {
    return 0;
}

