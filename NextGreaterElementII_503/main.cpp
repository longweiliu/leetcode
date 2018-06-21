#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    for (int i = 0; i < n - 1; ++i) {
        nums.push_back(nums[i]);
    }
    int m = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (nums[j] > nums[i]) {
                res[i] = nums[j];
                break;
            }
        }
    }
    return res;
}

int main() {
    return 0;
}

