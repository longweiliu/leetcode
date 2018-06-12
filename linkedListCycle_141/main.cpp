#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://www.cnblogs.com/hiddenfox/p/3408931.html

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    return 0;
}

