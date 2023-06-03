// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode* tail = head;
        int len = 1;

        while(tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        tail->next = head;
    
        int pos = len - (k%len);
        for(int i=0; i<pos; i++) tail = tail->next;
        
        head = tail->next; 
        tail->next = NULL;
        return head;
    }
};