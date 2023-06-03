// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        if(!root) return false;

        if(!root->left && !root->right) return true;

        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);
        bool curr;

        if(!root->left) curr = (root->val < root->right->val);
        else if(!root->right) curr = (root->left->val < root->val);
        else curr = (root->left->val < root->val) && (root->val < root->right->val);

        return left && right && curr;
    }
};