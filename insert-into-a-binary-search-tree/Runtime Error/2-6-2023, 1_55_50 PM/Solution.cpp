// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root->left && !root->right) return root;
        if(root->val == val) return root;
        else if(root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* parent = searchBST(root, val);
        TreeNode* newNode = new TreeNode(val);

        if(parent->val < val) parent->right = newNode;
        else parent->left = newNode;
        return root;
    }
};