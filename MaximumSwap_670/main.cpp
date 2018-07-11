#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumSwap(int num) {
    vector<int> v;
    while (num != 0) {
        v.push_back(num % 10);
        num /= 10;
    }
    reverse(v.begin(), v.end());
    int noSmallerAfter = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        bool is = true;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[i]) {
                is = false;
                break;
            }
        }
        if (is) break;
        else {
            noSmallerAfter++;
        }
    }
    cout << noSmallerAfter << endl;
    int max = noSmallerAfter;
    for (int i = noSmallerAfter; i < v.size(); ++i) {
        if (v[i] > v[max]) {
            max = i;
        }
    }
    cout << max << endl;
    int temp = v[max];
    v[max] = v[noSmallerAfter];
    v[noSmallerAfter] = temp;
    int res = 0;
    for (auto num : v) {
        res = res * 10 + num;
    }
    return res;
}

int main() {
    cout << maximumSwap(2736);
    return 0;
}

