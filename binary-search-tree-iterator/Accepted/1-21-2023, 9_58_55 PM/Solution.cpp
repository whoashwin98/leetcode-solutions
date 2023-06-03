// https://leetcode.com/problems/binary-search-tree-iterator

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    queue<int> in;
    void inorder(TreeNode* root, queue<int>& in) {
        if(root == NULL) return;
        inorder(root->left, in);
        in.push(root->val);
        inorder(root->right, in);
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root,in);
    }
    
    int next() {
        if(in.empty()) return INT_MAX;
        int val = in.front();
        in.pop();
        return val;
    }
    
    bool hasNext() {
        return !(in.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */