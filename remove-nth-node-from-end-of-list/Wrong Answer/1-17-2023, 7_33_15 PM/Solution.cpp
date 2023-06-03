// https://leetcode.com/problems/remove-nth-node-from-end-of-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
    
        int i=0; 
        while(fast != NULL && i <= n) {
            fast = fast->next;
            i++;
        }

        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next ? slow->next->next : NULL;
        return head;
    }
};