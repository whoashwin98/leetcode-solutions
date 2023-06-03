// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    int findLen(ListNode* head) {
        int len = 0;
        while(head != NULL) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        int i = 1;
        while(first != NULL && i < k) {
            first = first->next;
            i++;
        }

        int n = findLen(head);
        ListNode* last = head;
        i=0;
        while(last != NULL && i < n-k) {
            last = last->next;
            i++;
        }

        int temp = first->val;
        first->val = last->val;
        last->val = temp;

        return head;
    }
};