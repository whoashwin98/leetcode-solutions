// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *clone = new Node(-1);
        Node *tail = clone;

        // clone the linked list without random pointers
        Node *temp = head;
        while(temp != NULL) {
            Node *ptr = new Node(temp->val);
            tail->next = ptr;
            tail = ptr;
            temp = temp->next;
        }

        clone = clone->next;

        // change the links (similar to map but we are only manipulating links)
        temp = head;
        Node *cloneTemp = clone;
        while(temp != NULL && cloneTemp != NULL) {
            Node *tempNext = temp->next;
            temp->next = cloneTemp;
            temp = tempNext;

            Node *cloneNext = cloneTemp->next;
            cloneTemp->next = tempNext;
            cloneTemp = cloneNext;
        }
        
        // copy the random pointers

        temp = head;
        while(temp != NULL && temp->next != NULL) {
            temp->next->random = temp->random ? temp->random->next : temp->random;
            temp = temp->next->next;
        }

        // revert the links to original form
        temp = head;
        cloneTemp = clone;
        while(temp != NULL && cloneTemp != NULL) {
            temp->next = cloneTemp->next;
            temp = temp->next;

            if(temp != NULL) cloneTemp->next = temp->next;
            cloneTemp = cloneTemp->next;
        }

        return clone;
    }
};