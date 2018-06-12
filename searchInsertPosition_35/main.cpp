#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int index = 0;
    for (auto num : nums) {
        if (target  < num) {
            return index;
        }
        if (target == num) {
            return index;
        }
        ++index;
    }
    return index;
}

int searchInsertLogN(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) high= mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main() {

    return 0;
}


