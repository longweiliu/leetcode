#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        int numberToFind = target - nums[i];
        if (hash.find(numberToFind) != hash.end()) {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return vector<int>{hash[numberToFind], i};
        }
        hash[nums[i]] = i;
    }
    return result;
}

void walk(TreeNode *root, unordered_map<TreeNode *, string> &m, string code) {
    if (!root)
        return;
    m[root] = code;
    walk(root->left, m, code + '0');
    walk(root->right, m, code + '1');
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    unordered_map<TreeNode *, string> m;
    vector<int> result;
    walk(root, m, "0");
    string targetCode = m[target];
    int lenTarget = targetCode.size();
    for (auto pair : m) {
        string code = pair.second;
        int lenCode = code.size();
        int count = 0;
        if (lenCode <= lenTarget) {
            for (int i = 0; i < lenCode; ++i) {
                if (code[i] == targetCode[i]) {
                    count++;
                } else break;
            }
        } else {
            for (int i = 0; i < lenTarget; ++i) {
                if (code[i] == targetCode[i]) {
                    count++;
                } else break;
            }
        }
        if (lenCode + lenTarget - 2 * count == K) {
            result.push_back(pair.first->val);
        }
    }
    return result;

}


bool lemonadeChange(vector<int> &bills) {
    unordered_map<int, int> m;
    for (auto bill : bills) {
        if (bill == 5) {
            m[5] += 1;
        } else if (bill == 10) {
            if (m[5] == 0) return false;
            else {
                m[5] -= 1;
                m[10] += 1;
            }
        } else {
            if (!(m[5] >= 3 || (m[10] >= 1 && m[5] >= 1))) return false;
            if (m[10] >= 1) {
                m[10] -= 1;
                m[5] -= 1;
            } else {
                m[5] -= 3;
            }
        }
    }
    return true;
}

void print(vector<int> &nums) {
    for (auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

int partition(vector<int> &nums, int low, int high) {
    int key = nums[low];
    while (low < high) {
        while (nums[high] > key && high > low) {
            high--;
        }
        nums[low] = nums[high];
        while (nums[low] < key && high > low) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[high] = key;
    return high;
}

void quickSort(vector<int> &nums, int low, int high) {
    if (low >= high) return;
    int index = partition(nums, low, high);
    quickSort(nums, low, index - 1);
    quickSort(nums, index + 1, high);
}

void test() {
    vector<int> nums{5, 3, 2, 6, 4, 8, 1};
    quickSort(nums, 0, nums.size());
    for (auto num : nums) {
        cout << num << ' ';
    }
}

int main() {
    test();
    return 0;
}

