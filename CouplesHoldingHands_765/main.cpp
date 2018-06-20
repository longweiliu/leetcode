#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Union Find
int find(vector<int> &root, int i) {
    return (i == root[i]) ? i : find(root, root[i]);
}

int minSwapsCouples(vector<int> &row) {
    vector<int> root;
    int n = row.size();
    int count = n / 2;
    for (int i = 0; i < n; ++i) {
        root.push_back(i);
    }
    for (int i = 0; i < n; i += 2) {
        int a = find(root, row[i] / 2);
        int b = find(root, row[i + 1] / 2);
        if (a != b) {
            root[a] = b;
            --count;
        }
    }
    return n / 2 - count;
}

// Greedy
//int minSwapsCouples(vector<int> &row) {
//    int res = 0;
//    int n = row.size();
//    for (int i = 0; i < n; i += 2) {
//        if (row[i + 1] == row[i] ^ 1) continue;
//        ++res;
//        for (int j = i + 1; j < n; ++j) {
//            if (row[j] == (row[i] ^ 1)) {
//                row[j] = row[i + 1];
//                row[i + 1] = (row[i] ^ 1);
//                break;
//            }
//        }
//    }
//    return res;
//}

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);

    cout << minSwapsCouples(v);
    return 0;
}

