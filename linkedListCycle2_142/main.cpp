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

ListNode *getFirstMeetNode(ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
    }
    return NULL;
}

ListNode *detectCycle(ListNode *head) {
    if (getFirstMeetNode(head) == NULL) return NULL;
    else {
        ListNode *firstMeetNode = getFirstMeetNode(head);
        while (head != firstMeetNode) {
            head = head->next;
            firstMeetNode = firstMeetNode->next;
        }
        return head;
    }
}

int main() {
    return 0;
}

