#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/count-primes/hints/
int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int i = 2; i * i < n; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < n; j += i) {
            isPrime[j] = false;
        }
    }
    return count(isPrime.begin(), isPrime.end(), true);
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
//
//int countPrimes(int n) {
//    int count = 0;
//    for (int i = 2; i < n; ++i) {
//        if (isPrime(i)) count++;
//    }
//    return count;
//}

int main() {
    cout << countPrimes(10);
    return 0;
}

