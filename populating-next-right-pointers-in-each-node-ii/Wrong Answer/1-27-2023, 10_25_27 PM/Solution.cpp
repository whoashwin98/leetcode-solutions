// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

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
        
        if(root->left) {
            if(root->right) root->left->next = root->right;
            else if(root->next) {
                if(root->next->left) root->left->next = root->next->left;
                else root->left->next = root->next->right;
            }
        }

        if(root->right) {
            if(root->next) {
                if(root->next->left) root->right->next = root->next->left;
                else root->right->next = root->next->right;
            }
        }

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