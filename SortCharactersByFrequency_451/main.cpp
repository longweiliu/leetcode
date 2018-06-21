#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> mp;
    for (auto c : s) {
        mp[c] += 1;
    }
    sort(s.begin(), s.end(), [&](const char c1, const char c2) {
        if (mp[c1] == mp[c2]) {
            return c1 > c2;
        }
        return mp[c1] > mp[c2];
    });
    return s;
}

int main() {
    cout << frequencySort("loveleetcode");
    return 0;
}

