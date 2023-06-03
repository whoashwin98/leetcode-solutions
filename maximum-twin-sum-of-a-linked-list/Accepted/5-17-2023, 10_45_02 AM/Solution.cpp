// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    int len(ListNode* head) {
        if(head == NULL) return 0;
        int ans = 0;

        while(head != NULL) {
            head = head->next;
            ans++;
        }

        return ans;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode *curr, *prev, *nex;
        curr = head;
        prev = NULL;
        nex = NULL;

        while(curr != NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }

    void printList(ListNode* temp) {
        while(temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    int pairSum(ListNode* head) {
        int size = len(head);

        ListNode* temp = head;
        int i=0;
        while(i < size/2 - 1) {
            i++;
            temp = temp->next;
        }

        ListNode* second = temp->next;
        temp->next = NULL;
        
        second = reverseList(second);

        printList(head);
        cout << endl;
        printList(second);

        int maxi = INT_MIN;

        ListNode *temp1 = head;
        ListNode *temp2 = second;

        while(temp1 != NULL && temp2 != NULL) {
            maxi = max(maxi, temp1->val + temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return maxi;
    }
};