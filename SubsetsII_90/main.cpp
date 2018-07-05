#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int j) {
    res.push_back(temp);
    for (int i = j; i < nums.size(); ++i) {
        if (i > j && nums[i] == nums[i - 1]) continue;
        temp.push_back(nums[i]);
        dfs(res, temp, nums, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    dfs(res, temp, nums, 0);
    return res;
}

void subset(vector<int> &nums, set <vector<int>> &vec) {
    for (int i = 0; i < nums.size(); ++i) {
        vector<int> temp;
        for (int j = 0; j < nums.size(); ++j) {
            if (i != j) temp.push_back(nums[j]);
        }
        subset(temp, vec);
        vec.insert(temp);
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    set <vector<int>> s;
    vector<vector<int>> v;
    subset(nums, s);
    s.insert(nums);
    for (auto vec : s) {
        v.push_back(vec);
    }
    return v;
}


int main() {
    return 0;
}

