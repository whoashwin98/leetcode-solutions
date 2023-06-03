// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newList = new ListNode(-1);
        ListNode* tail = newList;

        ListNode *curr = head;
        ListNode *nextP = NULL;

        while(curr != NULL) {
            nextP = curr->next;
            
            if(nextP == NULL) {
                tail->next = curr;
                tail = curr;
                curr = curr->next;    
                continue;
            }

            if(curr->val == nextP->val) {
                int val = nextP->val;
                nextP = NULL;
                while(curr != NULL && curr->val == val) curr = curr->next;
                continue;
            }

            tail->next = curr;
            tail = curr;
            curr = curr->next;
        }

        newList = newList->next;
        return newList;
    }
};