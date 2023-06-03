// https://leetcode.com/problems/reorder-list

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return; 
        
        stack<ListNode*> st;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            st.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* list = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *ele = st.top();
            st.pop();
            ele->next = list->next;
            list->next = ele;
            list = list->next->next;
        }
        
        list->next = NULL;
    }
};