/*
Problem:
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode *pre, *cur;
        pre = head;
        cur = head;
        int step = 0;
        
        while (step < n)
        {
            cur = cur -> next;
            step++;
        }
        
        if (cur == NULL) 
        {
            head = head -> next;
            delete pre;
            return head;
        }
        
        while (cur->next != NULL)
        {
            pre = pre -> next;
            cur = cur -> next;
        }
        ListNode* temp = pre -> next;
        pre -> next = temp -> next;
        delete temp;
        return head;
    }
};