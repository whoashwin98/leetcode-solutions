// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void connectUtil(Node* root) {
        if(root == NULL || (!root->left && !root->right)) return;

        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = root->next ? root->next->left : NULL;
        connectUtil(root->left);
        connectUtil(root->right);
    }

public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        root->next = NULL;
        connectUtil(root);
        return root;
    }
};