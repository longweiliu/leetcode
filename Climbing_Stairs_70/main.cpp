#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int climbStairs(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int l = 1, r = 2, i = 2;
    while (i++ < n) {
        int temp = r;
        r += l;
        l = temp;
    }
    return r;
}

int main() {
    cout << climbStairs(3);
    return 0;
}

