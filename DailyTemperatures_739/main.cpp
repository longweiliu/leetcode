#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            auto t = st.top();
            st.pop();
            res[t] = i - t;
        }
        st.push(i);
    }
    return res;
}

//vector<int> dailyTemperatures(vector<int> &temperatures) {
//    int n = temperatures.size();
//    vector<int> res(n, 0);
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            if (temperatures[j] > temperatures[i]) {
//                res[i] = j - i;
//                break;
//            }
//        }
//    }
//    return res;
//}

int main() {
    map<int, stack<int>> mp;
    return 0;
}

