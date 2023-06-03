// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;

        ListNode* tail = head;
        ListNode* prev = NULL;

        unordered_map<ListNode*, ListNode*> prevNode;
        int len = 0;

        while(tail->next != NULL) {
            len++;
            prevNode[tail] = prev;
            prev = tail;
            tail = tail->next;
        }

        prevNode[head] = tail;
        tail->next = head;
        k = k % len;

        int i=1; 
        ListNode *temp = tail;
        while(i < k) {
            temp = prevNode[temp];
            i++;
        }

        head = temp;
        prevNode[temp]->next = NULL;
        return head;
    }
};