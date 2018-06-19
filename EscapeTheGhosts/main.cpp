#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
    int dis = 0;
    for (auto num : target) {
        dis += abs(num);
    }
    for (auto vec : ghosts) {
        if (abs(vec[0] - target[0]) + abs(vec[1] - target[1]) <= dis) {
            return false;
        }
    }
    return true;
}

int main() {

    return 0;
}

