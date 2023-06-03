// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    int lenList(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // if no list then return null
        if(head == NULL) return NULL;

        // if length of the list is less than K, no need to reverse
        if(lenList(head) < k) return head;

        // reverse first K nodes using iterative logic
        ListNode *next = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int count = 0;

        while(count < k && curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // now if the start of next K nodes is not null, then call recursively
        // and then point head's next to the remaining reversed part
        if(next != NULL) {
            head->next = reverseKGroup(next,k);    
        }
        
        // return the new head of the reversed list
        return prev;
    }
};