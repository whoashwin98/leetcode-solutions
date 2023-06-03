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
        unordered_map<Node*, Node*> mp;

        Node *clone = new Node(-1);
        Node *tail = clone;

        Node *temp = head;
        while(temp != NULL) {
            Node *ptr = new Node(temp->val);
            mp[temp] = ptr;
            tail->next = ptr;
            tail = ptr;
            temp = temp->next;
        }

        clone = clone->next;
        temp = clone;
        Node *first = head;

        while(temp != NULL) {
            temp->random = mp[first->random];
            temp = temp->next;
            first = first->next;
        }

        return clone;
    }
};