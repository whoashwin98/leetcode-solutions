// https://leetcode.com/problems/merge-k-sorted-lists

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
    class compare {
        public:
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newList = new ListNode(0);
        ListNode* tail = newList;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto list: lists) {
            if(list) pq.push(list);
        }

        while(pq.size() > 0) {
            ListNode *temp = pq.top();
            tail->next = temp;
            tail = temp;
            pq.pop();

            if(temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        return newList->next;
    }
};