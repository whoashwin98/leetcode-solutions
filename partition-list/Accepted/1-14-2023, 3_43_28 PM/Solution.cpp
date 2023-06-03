// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *newHead = new ListNode(-1);
        ListNode *tail = newHead;

        ListNode *temp = head;
        queue<int> less, more;

        while(temp != NULL) {
            if(temp->val < x) less.push(temp->val);
            else more.push(temp->val);
            temp = temp->next;
        }

        while(!less.empty()) {
            int front = less.front();
            less.pop();
            ListNode *node = new ListNode(front);
            tail->next = node;
            tail = node;
        }

        while(!more.empty()) {
            int front = more.front();
            more.pop();
            ListNode *node = new ListNode(front);
            tail->next = node;
            tail = node;
        }

        newHead = newHead->next;
        return newHead;
    }
};