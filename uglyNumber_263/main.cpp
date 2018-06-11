#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isUgly(int num) {
    if (num == 0) {
        return false;
    }
    for (int i = 2; i <= 5; i++) {
        while(num % i == 0) {
            num /= i;
        }
    }
    return num == 1;
}


int main() {
    isUgly(851);
    return 0;
}

//Just divide by 2, 3 and 5 as often as possible and then check whether we arrived at 1.
// Also try divisor 4 if that makes the code simpler / less repetitive.