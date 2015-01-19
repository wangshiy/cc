/*
Problem:
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        
        while (l1 != NULL || l2 != NULL)
        {
            int l1val = l1 == NULL ? INT_MAX : l1->val;
            int l2val = l2 == NULL ? INT_MAX : l2->val;
            
            if (l1val <= l2val)
            {
                cur->next = l1;
                l1 = l1 -> next;
            }
            
            else
            {
                cur->next = l2;
                l2 = l2 -> next;
            }
            
            cur = cur -> next;
        }
        
        cur = head -> next;
        delete head;
        return cur;
    }
};