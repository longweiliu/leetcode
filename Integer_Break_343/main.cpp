#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int ans = 1;
    while (n > 4) {
        ans *= 3;
        n -= 3;
    }
    ans *= n;
    return ans;
}

int main() {
    cout << integerBreak(10);
    return 0;
}

