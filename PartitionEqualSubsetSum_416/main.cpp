#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool back(vector<int> &nums, int sum, int start, int target) {
    if (start == nums.size()) return false;
    for (int i = start; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum == target) return true;
        else if (sum > target) {
            sum -= nums[i];
            return back(nums, sum, i + 1, target);
        }
    }
}

bool canPartition(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    if (nums.empty())
        return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    int target = sum / 2;
    return back(nums, 0, 0, target);

}

int main() {
    vector<int> nums{1, 5, 11, 3};
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a < b;
    });
    for (auto num : nums) {
        cout << num << ' ';
    }
//    cout << canPartition(nums);
    return 0;
}

