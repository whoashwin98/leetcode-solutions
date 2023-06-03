// https://leetcode.com/problems/sort-list

class Solution {
    ListNode* mergeLists(ListNode *left, ListNode *right) {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(left != NULL && right != NULL) {
            if(left->val <= right->val) {
                curr -> next = left;
                left = left -> next;
            }
            else {
                curr -> next = right;
                right = right -> next;
            }
            curr = curr ->next;
        }
                
        while(left != NULL) {
            curr -> next = left;
            left = left->next;
        }
        
        while(right != NULL) {
            curr -> next = right;
            right = right ->next;
        }      

        return ptr->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL) return head;        
        
        ListNode *middle = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // find middle
        while(fast !=  NULL && fast -> next != NULL)
        {
            middle = slow;
            slow = slow->next;          
            fast = fast ->next ->next;  
        }   

        // separate first and second halves
        middle -> next = NULL;            
        
        ListNode* left = sortList(head);    //left half recursive call
        ListNode* right = sortList(slow);    //right half recursive call
        
        return mergeLists(left, right);
    }
};