// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *head3 = new ListNode(-1);
        ListNode *tail3 = head3;

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        while(head1 != NULL && head2 != NULL) {
            if(head1->val < head2->val) {
                tail3->next = head1;
                tail3 = head1;
                head1 = head1->next;
            }

            else {
                tail3->next = head2;
                tail3 = head2;
                head2 = head2->next;
            }
        }

        while(head1 != NULL) {
            tail3->next = head1;
            tail3 = head1;
            head1 = head1->next;
        }

        while(head2 != NULL) {
            tail3->next = head2;
            tail3 = head2;
            head2 = head2->next;
        }

        head3 = head3->next;
        return head3;
    }
};