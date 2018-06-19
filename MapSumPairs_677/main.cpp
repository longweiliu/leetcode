#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class MapSum {
private:
    map<string, int> theMap;
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        theMap[key] = val;
    }

    int sum(string prefix) {
        int sum = 0;
        for (auto it = theMap.begin(); it != theMap.end(); ++it) {
            string sub = it->first.substr(0, prefix.size());
            if (prefix == sub)
                sum += it->second;
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main() {
    return 0;
}

