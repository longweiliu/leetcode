#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
    int n = findNums.size();
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (findNums[i] == nums[j]) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[k] > nums[j]) {
                        res[i] = nums[k];
                        break;
                    }
                }
                break;
            }
        }
    }
    return res;
}

int main() {

    return 0;
}

