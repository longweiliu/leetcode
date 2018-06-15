#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string customSortString(string S, string T) {
    sort(T.begin(), T.end(), [&](const char c1, const char c2) {
//        if (S.find(c1) != string::npos && S.find(c2) != string::npos) {
        return S.find(c1) < S.find(c2);
//        }
//        return false;
    });
    return T;
}

int main() {
    cout << customSortString("cba", "abcd");
    return 0;
}

