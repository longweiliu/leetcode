#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            int left = mid;
            int right = mid;
            while (left >= 0 && nums[--left] == target);
            while (right <= nums.size() - 1 && nums[++right] == target);
            vector<int> ans;
            ans.push_back(left + 1);
            ans.push_back(right - 1);
            return ans;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    vector<int> ans;
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    auto ans = searchRange(nums, 0);
    for (auto i : ans) {
        cout << i << ' ';
    }
    return 0;
}


//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//Example 1:
//
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//Example 2:
//
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]