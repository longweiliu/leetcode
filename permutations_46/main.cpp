#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

bool isUnique(vector<int> &nums, int begin, int end) {
    for (int i = begin; i < end; i++) {
        if (nums[i] == nums[end]) {
            return false;
        }
    }
    return true;
}

void print(vector<vector<int>> ans) {
    for (auto vec : ans) {
        for (auto num : vec) {
            cout << num << ' ';
        }
        cout << endl;
    }
}

void permutation(vector<vector<int>> &ans, vector<int> &nums, int begin) {
    if (begin == nums.size()) {
        ans.push_back(nums);
    } else {
        for (int i = begin; i < nums.size(); i++) {
            if (isUnique(nums, begin, i)) {
                swap(nums, begin, i);
                permutation(ans, nums, begin + 1);
                swap(nums, begin, i);
            }
        }
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    permutation(ans, nums, 0);
    sort(ans.begin(), ans.end());
    print(ans);
    return ans;
}


int main() {
    vector<int> nums;
    for (int i = 1; i <= 3; i++) {
        nums.push_back(i);
    }
    nums.push_back(3);
    vector<vector<int>> ans = permute(nums);
    return 0;
}

// https://www.cnblogs.com/zhouthanos/p/3807495.html