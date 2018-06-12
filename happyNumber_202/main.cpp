#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSquareSum(int n) {
    int sum = 0, temp;
    while (n) {
        temp = n % 10;
        sum += temp * temp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = getSquareSum(slow);
        fast = getSquareSum(fast);
        fast = getSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}

int main() {
    isHappy(19);
    return 0;
}

