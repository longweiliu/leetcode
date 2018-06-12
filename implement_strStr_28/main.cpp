#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle) {
    size_t i = haystack.find(needle);
    cout << i;
}

int main() {
    strStr("helloll", "");
    return 0;
}

