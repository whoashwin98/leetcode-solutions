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
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextP = NULL;

        while(curr != NULL) {
            nextP = curr->next;

            if(nextP != NULL && curr->val == nextP->val) {
                int val = nextP->val;
                while(curr != NULL && curr->val == val) curr = curr->next;
                
                if(prev != NULL) prev->next = curr;
                else head = curr;
                continue;
            }

            prev = curr;
            curr = nextP;
        }

        return head;
    }
};