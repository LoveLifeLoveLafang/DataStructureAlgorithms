#include <iostream>
#include "solution.h"

using namespace std;

int main() {
    ListNode *head;
    ListNode *node = new ListNode(2);
    head = node;
    node = new ListNode(5);
    node->next = head;
    head = node;
    node = new ListNode(2);
    node->next = head;
    head = node;
    node = new ListNode(3);
    node->next = head;
    head = node;
    node = new ListNode(4);
    node->next = head;
    head = node;
    node = new ListNode(1);
    node->next = head;
    head = node;


    Solution *s = new Solution();
    head = s->partition(head, 3);
    ListNode* p = head;
    cout << s->getLen(p) << endl;
//    while(p != NULL) {
//        cout << p->val << " ";
//        p = p->next;
//    }
//    cout << endl;
    return 0;
}