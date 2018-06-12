#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int missingNumber(vector<int>& nums) {
    int size = nums.size();
    int sum = 0;
    sum = size * (size + 1) / 2;
    return sum - accumulate(nums.begin(), nums.end(), 0);
}

int main() {
    return 0;
}

