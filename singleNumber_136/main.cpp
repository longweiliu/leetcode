#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (auto num : nums) {
        ans ^= num;
    }
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    cout << singleNumber(v);
    return 0;
}

