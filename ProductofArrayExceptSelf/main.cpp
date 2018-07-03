#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int product = 1;
    vector<int> res;
    for (auto num : nums) {
        product *= num;
    }
    for (auto num : nums) {
        res.push_back(product / num);
    }
    return res;
}

int main() {
    return 0;
}

