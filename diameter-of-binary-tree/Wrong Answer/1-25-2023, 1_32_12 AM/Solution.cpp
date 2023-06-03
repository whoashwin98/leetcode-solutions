// https://leetcode.com/problems/diameter-of-binary-tree

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
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        return max(lh,rh)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        return lh+rh;
    }
};