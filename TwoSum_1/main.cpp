#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

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

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    vector<int> ans = twoSum(v, 9);
    for (auto num : ans) {
        cout << num << ' ';
    }
    return 0;
}

