// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

/**
 * definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head || !head->next) return head; 
        ListNode *prev = NULL, *newHead = NULL;
        ListNode *first = head, *second = head->next;
        while(second) {
            first->next = second->next;
            second->next = first;
            if(!newHead) newHead = second;
            if(prev) prev->next = second;
            prev = first;
            first = first->next;
            second = first ? first->next : NULL;
        }
        return newHead;
    }
};
