#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void extendPalindrome(const string& s, int left, int right, int& count) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        count++; --left; ++right;
    }
}
int countSubstrings(string s) {
    if (s.empty()) return 0;
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        extendPalindrome(s, i, i, count);
        extendPalindrome(s, i, i+1, count);
    }
    return count;
}

int main() {
    cout << countSubstrings("aaaa");
    return 0;
}

