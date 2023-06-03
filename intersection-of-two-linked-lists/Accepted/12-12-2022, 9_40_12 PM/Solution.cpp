// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> isVisited;

        ListNode* tempA = headA;
        while(tempA != NULL) {
            isVisited[tempA] = true;
            tempA = tempA->next;
        }

        ListNode *tempB = headB;
        while(tempB != NULL) {
            if(isVisited[tempB]) return tempB;
            tempB = tempB->next;
        }

        return NULL;
    }
};