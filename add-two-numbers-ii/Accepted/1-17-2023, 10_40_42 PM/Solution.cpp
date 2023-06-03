// https://leetcode.com/problems/add-two-numbers-ii

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1, num2;

        while(l1 != NULL) {
            num1.push(l1->val);
            l1 = l1->next;
        }

        while(l2 != NULL) {
            num2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        stack<int> res;

        while(!num1.empty() && !num2.empty()) {
            int dig1 = num1.top();
            num1.pop();
            int dig2 = num2.top();
            num2.pop();

            int sum = dig1 + dig2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            res.push(sum);
        }

        while(!num1.empty()) {
            int dig1 = num1.top();
            num1.pop();

            int sum = dig1 + carry;
            carry = sum / 10;
            sum = sum % 10;

            res.push(sum);
        }

        while(!num2.empty()) {
            int dig2 = num2.top();
            num2.pop();

            int sum = dig2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            res.push(sum);
        }

        if(carry > 0) res.push(carry);

        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;

        while(!res.empty()) {
            ListNode* ptr = new ListNode(res.top());
            res.pop();
            tail->next = ptr;
            tail = ptr;
        } 

        return newHead->next;
    }
};