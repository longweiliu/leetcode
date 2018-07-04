#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <random>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countSubtreeSums(TreeNode *r, unordered_map<int, int> &counts, int &maxCount) {
    if (r == nullptr) return 0;

    int sum = r->val;
    sum += countSubtreeSums(r->left, counts, maxCount);
    sum += countSubtreeSums(r->right, counts, maxCount);
    ++counts[sum];
    maxCount = max(maxCount, counts[sum]);
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> counts;
    int maxCount = 0;
    countSubtreeSums(root, counts, maxCount);
    vector<int> maxSums;
    for (const auto &x :  counts) {
        if (x.second == maxCount) maxSums.push_back(x.first);
    }
    return maxSums;
}




//int getTreeSum(TreeNode *root) {
//    if (!root) return 0;
//    return root->val + getTreeSum(root->left) + getTreeSum(root->right);
//}
//
//void getSumMap(TreeNode *root, map<int, int> &m) {
//    if (!root)
//        return;
//    m[getTreeSum(root)] += 1;
//    getSumMap(root->left, m);
//    getSumMap(root->right, m);
//}
//
//vector<int> findFrequentTreeSum(TreeNode *root) {
//    map<int, int> m;
//    vector<int> v;
//    getSumMap(root, m);
//    int maxCount = -1;
//    for (auto pair : m) {
//        if (pair.second > maxCount) {
//            maxCount = pair.second;
//        }
//    }
//    for (auto pair : m) {
//        if (pair.second == maxCount) {
//            v.push_back(pair.first);
//        }
//    }
//    return v;
//}


int main() {
    set<int> s;
    vector<int> v;
    v.reserve(10000);
    for (int i = 0; i < 10000; ++i) {
        v.push_back(i);
    }
    default_random_engine e;
//    e.seed(10);
    for (int i = 0; i < 10000; ++i) {
        s.insert(v[e() % 10000]);
    }
    cout << s.size();
    return 0;
}

