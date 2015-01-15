/*
Problem:
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode* prev = head;
        ListNode* post = head->next;
        
        while(post != NULL)
        {
            if (prev->val == post->val)
            {
                ListNode* temp = post;
                post = post->next;
                prev->next = post;
                delete temp;
                continue;
            }
            prev = prev->next;
            post = post->next;
        }
        
        return head;
    }
};