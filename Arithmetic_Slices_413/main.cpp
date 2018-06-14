#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool
consecutive(const vector<int> &A, const int &first, const int &second, const int &third, const int &fourth) {
    return A[second] - A[first] == A[fourth] - A[third];
}

int numberOfArithmeticSlices(vector<int> &A) {
    int m = A.size();
    if (m < 3) return 0;

    //Make a dp array where dp[i] signifies the Number of Artimetic Sequence till A[i]
    vector<int> dp(m);
    int count = 0;

    //Aritmatic Sequnce has to be atleast 3 numbers
    dp[0] = 0;
    dp[1] = 0;


    //Check for each A[i]
    for (int i = 2; i < m; i++) {
        dp[i] = consecutive(A, i, i - 1, i - 1, i - 2) ? dp[i - 1] + 1 : 0;
        count += dp[i];
    }

    return count;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << numberOfArithmeticSlices(v);
    return 0;
}

