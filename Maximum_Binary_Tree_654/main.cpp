#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2018-06-13 23:32:51 😴
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *construct(vector<int> &nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int max_index = left;
    for (int i = left; i <= right; ++i) {
        if (nums[i] > nums[max_index]) {
            max_index = i;
        }
    }
    TreeNode *head = new TreeNode(nums[max_index]);
    head->left = construct(nums, left, max_index - 1);
    head->right = construct(nums, max_index + 1, right);
    return head;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    TreeNode *head = construct(nums, 0, nums.size() - 1);
    return head;
}

int main() {
    return 0;
}

