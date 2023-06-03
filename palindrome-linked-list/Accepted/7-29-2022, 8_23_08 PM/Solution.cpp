// https://leetcode.com/problems/palindrome-linked-list

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
        ListNode *reverseLinkedList(ListNode *&head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nextp = NULL;

        while(curr != NULL) {
            nextp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextp;
        }

        return prev;
    }

    int findSize(ListNode *head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    bool isPalindrome(ListNode *head) {

        if(head == NULL || head->next == NULL) return true;

        int size = findSize(head);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prevSlow = NULL;
        do {
            fast = fast->next;
            if(fast->next != NULL) fast = fast->next;
            prevSlow = slow;
            slow = slow->next;
        } while(fast->next != NULL);

        if(size&1) slow = slow->next;
        slow = reverseLinkedList(slow);
        prevSlow->next = slow;

        ListNode *temp1 = slow;
        ListNode *temp2 = head;

        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};