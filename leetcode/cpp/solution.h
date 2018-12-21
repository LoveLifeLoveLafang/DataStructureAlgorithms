//
// Created by nicholas on 2018/12/10.
//

#ifndef CC_SOLUTION_H
#define CC_SOLUTION_H

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//23.题辅助函数
//小的排前面
struct cmp{
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    /*****************************************
     *****************************************
     ********** Topic: Linked List ***********
     *****************************************
     *****************************************
     * */

    //206.reverse Linked List
    /*
     * reversed by a dummy node
     * */
    ListNode *reverseList(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        while (head->next != NULL) {
            ListNode *p = head->next;
            head->next = head->next->next;
            p->next = dummy->next;
            dummy->next = p;
        }

        return dummy->next;
    }

    //  reverse linked list II
    /*
     * 92. count from zero, m and n are index
     * 使用两个指针来完成，一个指向第m-1个， 一个指向原第m个
     * */
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *before = dummy, *last = head;

        int count = n - m;

        while(m > 1) {
            before = before->next;
            last = last->next;
            m--;
        }

        while(count > 0) {
            ListNode* p = last->next;
            last->next = p->next;
            p->next = before->next;
            before->next = p;
            count--;
        }

        return dummy->next;
    }

    /*
     * 160. intersection of two Linked lists
     *  方法一：借助辅助集合或者map
     * */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        int ALength = getLen(headA);
        int BLength = getLen(headB);

        ListNode *a = headA;
        ListNode *b = headB;

        int count = 0;

        if ( ALength > BLength ) {
            count = ALength - BLength;
            while(count > 0) {
                a = a->next;
                count--;
            }
        } else {
            count = BLength - ALength;
            while(count > 0) {
                b = b->next;
                count--;
            }
        }

        while(a != NULL && b != NULL) {
            if ( a == b )
                return a;
            a = a->next;
            b = b->next;
        }

        return NULL;
    }

    int getLen(ListNode* head) {
        ListNode* cur = head;
        int count = 1;
        while(cur != NULL) {
            cur = cur->next;
            count++;
        }
        return count;
    }

    /*160. intersection of two Linked lists
     *  方法一：先求出两个链表的长度， 从等长位置开始遍历，一一比对各个节点的指针
     * */
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> mp;

        ListNode *cur = headA;
        while(cur != NULL) {
            mp[cur] = true;
            cur = cur->next;
        }

        cur = headB;
        while(cur != NULL) {
            map<ListNode*, bool>::iterator iter = mp.find(cur);
            if ( iter != mp.end() )
                return cur;
            cur = cur->next;
        }

        return NULL;
    }

    /*
     * 141.Linked List cycle
     * method1： use a map to store the pointer of node
     * */
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> mp;

        ListNode *cur = head;
        while(cur != NULL) {
            map<ListNode*, bool>::iterator iter = mp.find(cur);
            if ( iter != mp.end() )
                return true;
            else
                mp[cur] = true;
            cur = cur->next;
        }
        return false;
    }

    /*
     * 141.Linked List cycle
     * method2: use a quick pointer and a slower pointer, when they are eaual, return true, else false
     * */
    bool hasCycle1(ListNode *head) {
        if ( head == NULL || head->next == NULL )
            return false;
        ListNode *quick = head->next->next;
        ListNode *slow = head;


        while( quick != NULL && slow != NULL && quick->next != NULL ) { //容易出错位置， 此处容易丢掉quick->next != NULL条件
            if (quick == slow) {
                return true;
            }
            quick = quick->next->next;
            slow = slow->next;
        }
        return false;
    }

    /*
     * 86.Partition List
     * use construct two linked lists, one is smaller than x, the other is bigger than x, merge the two linked lists
     * */
    //不能使用原节点
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = new ListNode(0);
        ListNode *bigHead = new ListNode(0);
        ListNode *small = smallHead;
        ListNode *big = bigHead;

        while( head != NULL) {
            ListNode *cur = new ListNode(head->val);
            if ( cur->val < x ) {
                    small->next = cur;
                    small = small->next;
            } else {
                    big->next = cur;
                    big = big->next;
            }
            head = head->next;
        }

        small->next = bigHead->next;
        return smallHead->next;
    }

    /*
     * 138. copy list with random pointer
     *
     * */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if ( head == NULL)
            return NULL;

        //first step， insert the same node
        RandomListNode *cur = head;
        while(cur != NULL) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }

        //complete the random pointers
        RandomListNode *pre = head;
        cur = head->next;
        while(cur != NULL) {
            if (pre->random != NULL) {
                cur->random = pre->random->next;
            }

            if (cur->next == NULL) //此处需要判断cur是否是最后一个节点
                break;
            pre = pre->next->next;
            cur = pre->next;
        }

        //second step, split the linked list
        RandomListNode *newhead = new RandomListNode(0);
        RandomListNode *temp = newhead;
        pre = head;
        cur = head->next;
        while(cur != NULL) {
            pre->next = pre->next->next;
            pre = pre->next;
            cur->next = temp->next;
            temp->next = cur;
            temp = temp->next;  //标记指针记得移动
            if (pre == NULL)    //此处容易忘记判断pre指针是否为空
                break;
            cur = pre->next;
        }

        return newhead->next;
    }

    /*
     * 21.Merge Two Sorted Lists
     * */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while(l1 != NULL && l2 != NULL) {
            if ( l1->val <= l2->val ) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if ( l1 != NULL)
            cur->next = l1;
        if ( l2 != NULL )
            cur->next = l2;

        return dummy->next;
    }

    /*
     * 23.Merge k Sorted lists
     * */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> Q;

        for (int i = 0; i < lists.size(); ++i) {
            if ( lists[i] ) Q.push(lists[i]);
        }

        ListNode* head = NULL, *pre = NULL, *tmp = NULL;
        while(!Q.empty()) {
            tmp = Q.top();
            Q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) Q.push(tmp->next);
        }
        return head;
    }

    /*
        19.删除链表的倒数第N个节点
    */
    ListNode *removeNthFromEnd(ListNode* head, int n) {
        if ( head == NULL )
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p1 = dummy, *p2 = dummy;

        while(p2 != NULL && n > 0) {
            n--;
            p2 = p2->next;
        }

        while(p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if ( p1 != NULL && p1->next != NULL )
            p1->next = p1->next->next;

        return dummy->next;
    }

    /*
        142.环形链表II
    */
   ListNode *detectCycle(ListNode *head) {
        //快慢指针从头部出发
        ListNode *fast = head, *slow = head;

        while(true) {
            //如果fast走到null位置表示链表无环
            if ( fast == NULL || fast->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if ( fast == slow )
                break;
        }

        //第一次相遇，fast指针重新指回头部，slow保留在相遇的地方
        slow = head;
        while( slow != fast ) {
            //fast改为每次走一步，slow不变，再次相遇时即为入环位置
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    /*
        2.两数相加
    */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        int i = 0; //进位
        while (l1 != NULL && l2 != NULL)
        {
            int j = (l1->val + l2->val + i) % 10;
            i = (l1->val + l2->val + i) / 10;
            cur->next = new ListNode(j);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            int j = (l1->val + i) % 10;
            i = (l1->val + i) / 10;
            cur->next = new ListNode(j);
            cur = cur->next;
            l1 = l1->next;
        }

        while(l2 != NULL) {
            int j = (l2->val + i) % 10;
            i = (l2->val + i) / 10;
            cur->next = new ListNode(j);
            cur = cur->next;
            l2 = l2->next;
        }

        if (i > 0) {
            cur->next = new ListNode(i);
        }

        return dummy->next;
    }

    /*
        430.扁平化多级双向链表
    */


    /*
        61.旋转链表
    */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return NULL;
        int length = 0;
        ListNode *cur = head;
        while(cur != NULL) {
            cur = cur->next;
            length++;
        }
        k = k % length;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        cur = dummy;
        int count = length - k;
        while(count > 0 && cur != NULL) {
            cur = cur->next;
            count--;
        }

        ListNode *p = cur;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = dummy->next;
        dummy->next = cur->next;
        cur->next = NULL;
        return dummy->next;
    }

    /*
        203.移除链表元素
    */
    ListNode* removeElements(ListNode *head, int val) {
        if (head == NULL)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while(cur != NULL) {
            if (cur->next != NULL && cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }

    /*
        328.奇偶链表
    */
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *l1 = head, *p1 = head;
        ListNode *l2 = head->next, *p2 = head->next;

        ListNode *last1 = head, *last2 = head->next;
        while (p1 != NULL && p1->next != NULL && p2 != NULL && p2->next)
        {
            p1 = p1->next->next;
            p2 = p2->next->next;
            last1->next = p1;
            last2->next = p2;
            last1 = last1->next;
            last2 = last2->next;
        }

        last1->next = l2;
        return l1;
    }

    /*
        234.回文链表
    */
    bool isPalindrome(ListNode *head) {
        if(head == NULL)
            return true;
        ListNode *cur = head;
        vector<int> vec;
        while(cur != NULL) {
            vec.push_back(cur->val);
            cur = cur->next;
        }

        int i = 0, j = vec.size() - 1;
        while(i < j) {
            if (vec[i] != vec[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
};

#endif //CC_SOLUTION_H
