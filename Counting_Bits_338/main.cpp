#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countBits(int num) {
    vector<int> v(num+1,0);
    for (int i = 1; i <= num; ++i) {
        v[i] = v[i >> 1] + i & 1;
    }
    return v;
}

//vector<int> countBits(int num) {
//    vector<int> v;
//    for (int i = 0; i <= num; ++i) {
//        v.push_back(__builtin_popcount(i));
//    }
//    return v;
//}

int main() {
    cout << __builtin_popcount(3);
    return 0;
}

