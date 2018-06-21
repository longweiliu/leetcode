#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<ListNode *> s1, s2, s;
    while (l1) {
        s1.push(l1);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2);
        l2 = l2->next;
    }
    int extra = 0;
    while (!s1.empty() || !s2.empty() || extra) {
        int sum = (!s1.empty() ? s1.top()->val : 0) + (!s2.empty() ? s2.top()->val : 0) + extra;
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
        extra = sum / 10;
        ListNode *temp = new ListNode(sum % 10);
        s.push(temp);
    }
    ListNode preHead(0), *p = &preHead;
    while (!s.empty()) {
        p->next = s.top();
        s.pop();
        p = p->next;
    }
    return preHead.next;
}

int main() {
    stack<int> s;
    cout << (s.top() == NULL);
    s.pop();
    return 0;
}

