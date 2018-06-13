#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int reverse(int x) {
    int ans = 0;
    while (x) {
        int newAns = ans * 10 + x % 10;
        if ((newAns - x % 10) / 10 != ans)
            return 0;
        ans = newAns;
        x /= 10;
    }
    return ans;
}

int main() {
    cout << reverse(1534236469);
    return 0;
}

//Given a 32-bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//Output: 321
//Example 2:
//
//Input: -123
//Output: -321
//Example 3:
//
//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only store integers
// within the 32-bit signed integer range: [−231,  231 − 1].
// For the purpose of this problem,
// assume that your function returns 0 when the reversed integer overflows.