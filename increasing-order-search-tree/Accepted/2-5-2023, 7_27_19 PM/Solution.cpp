// https://leetcode.com/problems/increasing-order-search-tree

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
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in) {
        if(root == NULL) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(!root->left && !root->right) return root;

        vector<int> in;
        inorder(root, in);
        
        TreeNode* newRoot = new TreeNode(-1);
        TreeNode* temp = newRoot;

        for(int num : in) {
            temp->right = new TreeNode(num);
            temp->left = NULL;
            temp = temp->right;
        }

        return newRoot->right;
    }
};