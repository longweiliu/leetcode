#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> v, int x) {
    int r = x;
    while (v[r] != r) {
        r = v[r];
    }
    return r;
}

int findCircleNum(vector<vector<int>> &M) {
    vector<int> vec;
    int groups = M.size();
    for (int i = 0; i < M.size(); ++i) {
        vec.push_back(i);
    }
    for (int i = 0; i < M.size(); ++i) {
        for (int j = i + 1; j < M.size(); ++j) {
            if (M[i][j] == 1) {
                int lead1 = find(vec, i);
                int lead2 = find(vec, j);
                if (lead1 != lead2) {
                    vec[lead1] = lead2;
                    groups--;
                }
            }
        }
    }

    return groups;
}

int main() {
    vector<vector<int>> vec{{1, 0, 0, 1},
                            {0, 1, 1, 0},
                            {0, 1, 1, 1},
                            {1, 0, 1, 1}};
    findCircleNum(vec);
    return 0;
}

