// https://leetcode.com/problems/reverse-linked-list-ii

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
    void reverseLL(ListNode* &head, ListNode* &tail) {
        if(head == tail) return;

        tail->next = NULL;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextP = NULL;

        while(curr != NULL) {
            nextP = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextP;
        }

        head = prev;
        while(prev->next != NULL) prev = prev->next;
        tail = prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode *leftNode = head;
        ListNode *prev = NULL;
        int i=0;

        while(i < left-1) {
            prev = leftNode;
            leftNode = leftNode->next;
            i++;
        }
        
        ListNode *rightNode = NULL;
        ListNode *nextP = head;
        i = 0;
        while(i < right) {
            rightNode = nextP;
            nextP = nextP->next;
            i++;
        }

        reverseLL(leftNode, rightNode);

        if(prev != NULL) prev->next = leftNode;
        else head = leftNode;
        rightNode->next = nextP;

        return head;
    }
};