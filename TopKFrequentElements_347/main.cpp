#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> mp;
    vector<pair<int, int>> vec;
    vector<int> res;
    for (auto num : nums) {
        mp[num] += 1;
    }
    for (auto pair : mp) {
        vec.push_back(pair);
    }
    sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }
    );
    for (int i = 0; i < k; ++i) {
        res.push_back(vec[i].first);
    }
    return res;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    topKFrequent(nums, 2);
    return 0;
}

