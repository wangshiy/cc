/*
Problem:
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*
Solution:
一个走一个，一个走两个，速度差为1，总会有相遇的一天
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
    bool hasCycle(ListNode *head) 
    {
        if (head == NULL) return false;
        ListNode* first = head;
        ListNode* second = head->next;
        
        while (first != NULL && second != NULL)
        {
            if (first == second) return true;
            first = first->next;
            second = second->next;
            if (second == NULL) return false;
            second = second->next;
        }
        return false;
    }
};