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

    int lenLL(ListNode* head) {
        if(head == NULL) return 0;

        int ans = 0;
        while(head != NULL) {
            ans++;
            head = head->next;
        }

        return ans;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lenLL(head);
        int delPos = len - n + 1;

        if(len == 1) return NULL;

        int i = 1;
        ListNode *curr = head;
        ListNode *prev = NULL;

        while(i < delPos) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        prev->next = curr->next;
        delete curr;
        return head;
    }
};