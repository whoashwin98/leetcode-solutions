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
    ListNode* removeElements(ListNode* &head, int val) {
        if(head == NULL) return head;

        ListNode *prev = head;
        ListNode *curr = head->next;

        if(head->val == val) {
            while(head != NULL && head->val == val) head = head->next;
        }

        if(head == NULL) return head;
        else {
            while(curr != NULL) {
                if(curr->val == val) {
                    prev->next = curr->next;
                }
                prev = curr;
                curr = curr->next;
            }
            return head;
        }
    }
};