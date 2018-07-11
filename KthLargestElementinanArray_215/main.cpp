#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    for (auto num : nums) {
        cout << num << ' ';
    }
    return nums[k];
}

int main() {
    vector<int> v{3, 7, 1, 2, 6};
    findKthLargest(v, 2);

    return 0;
}

