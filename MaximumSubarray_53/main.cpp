#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums) {
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(v);
    return 0;
}

