// https://leetcode.com/problems/add-two-numbers

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
    void insertAtHead(ListNode *&head, int d)
    {
        ListNode *newListNode = new ListNode(d);
        newListNode->next = head;
        head = newListNode;
    }

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

    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *result = NULL;
        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            insertAtHead(result,sum);
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            int sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            insertAtHead(result,sum);
            l1 = l1->next;
        }

        while(l2 != NULL) {
            int sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            cout << sum << " " << carry << endl;
            insertAtHead(result,sum);
            l2 = l2->next;
        }

        if(carry != 0) {
            insertAtHead(result,carry);
            carry /= 10;
        }

        return reverseLinkedList(result);
    }
};