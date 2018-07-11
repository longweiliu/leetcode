#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findTarget(vector<int> &nums, int start, int S) {
    if (start == nums.size() - 1) {
        if (nums[start] == S && nums[start] == -S) return 2;
        else if (nums[start] == S || nums[start] == -S) return 1;
        else return 0;
    }
    return findTarget(nums, start + 1, S - nums[start]) + findTarget(nums, start + 1, S + nums[start]);
}

int findTargetSumWays(vector<int> &nums, int S) {
    int res = findTarget(nums, 0, S);
    return res;
}

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3);
    return 0;
}

