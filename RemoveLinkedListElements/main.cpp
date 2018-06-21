#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeElements(ListNode *head, int val) {
    if (head == NULL)
        return NULL;

    ListNode *curr = head;
    ListNode *pre = NULL;

    while (curr) {
        if (curr->val == val) {
            if (pre)
                pre->next = curr->next;
            else
                head = head->next;
        } else {
            pre = curr;
        }
        curr = curr->next;
    }
    return head;
}

//ListNode *removeElements(ListNode *head, int val) {
//    if (!head) return head;
//    head->next = removeElements(head->next, val);
//    return head->val == val ? head->next : head;
//}

//ListNode* removeElements(ListNode* head, int val) {
//    ListNode preHead(0), *p = &preHead;
//    while (head) {
//        if (head->val != val) {
//            p->next = new ListNode(head->val);
//            p = p->next;
//        }
//        head = head->next;
//    }
//    return preHead.next;
//}

int main() {
    return 0;
}

