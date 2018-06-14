#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices) {
    if (prices.empty())
        return 0;
    int size = prices.size();
    vector<int> dp(size);
    for (int i = 1; i < size; ++i) {
        if (prices[i] <= prices[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
        }
    }
    return dp[size - 1];
}

int main() {
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    cout << maxProfit(v);
    return 0;
}

