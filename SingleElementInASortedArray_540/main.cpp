#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int ans = 0;
    for (auto num : nums) {
        ans ^= num;
    }
    return ans;
}

int main() {
    return 0;
}

