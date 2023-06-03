// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
        if(head == NULL) return NULL;
        ListNode *temp = head;
        ListNode *nextNode = NULL;
        while(temp->next != NULL) {
            nextNode = temp->next;
            if(temp->val == nextNode->val) {
                temp->next = nextNode->next;
                nextNode = NULL;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};