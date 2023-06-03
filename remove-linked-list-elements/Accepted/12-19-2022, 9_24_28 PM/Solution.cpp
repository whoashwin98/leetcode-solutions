// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        
        ListNode *curr = head;
        ListNode *nex = head->next;

        while(nex != NULL) {
            if(nex->val == val) {
                curr->next = nex->next;
                nex = curr->next;
            }

            else {
                curr = nex;
                nex = nex->next;
            }
        }
        
        if(head->val == val) head = head->next;
        return head;
        
    }
};