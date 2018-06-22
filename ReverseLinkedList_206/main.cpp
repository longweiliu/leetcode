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

// iterative
//ListNode *reverseList(ListNode *head) {
//    ListNode *pre = NULL;
//    ListNode *curr = head;
//    while (curr) {
//        ListNode *nextTemp = curr->next;
//        curr->next = pre;
//        pre = curr;
//        curr = nextTemp;
//    }
//    return pre;
//}


//ListNode *reverseList(ListNode *head) {
//    stack<ListNode *> s;
//    ListNode preHead(0), *p = &preHead;
//    while (head) {
//        s.push(head);
//        head = head->next;
//    }
//    while (!s.empty()) {
//        p->next = s.top();
//        s.pop();
//        p = p->next;
//    }
//    p->next = NULL;
//    return preHead.next;
//}

int main() {
    return 0;
}

