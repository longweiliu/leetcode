#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int> &nums) {
    int count = 0;
    for (auto iter = nums.begin(); iter != nums.end();) {
        if (*iter == 0) {
            nums.erase(iter);
            count++;
        } else {
            ++iter;
        }
    }
    for (int i = 0; i < count; ++i) {
        nums.push_back(0);
    }
}

int main() {
    vector<int> v{0};
    moveZeroes(v);
    return 0;
}

