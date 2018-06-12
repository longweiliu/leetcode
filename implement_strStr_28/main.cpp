#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle) {
    int i = haystack.find(needle);
    cout << i;
}

int main() {
    strStr("helloll", "uhi");
    return 0;
}

