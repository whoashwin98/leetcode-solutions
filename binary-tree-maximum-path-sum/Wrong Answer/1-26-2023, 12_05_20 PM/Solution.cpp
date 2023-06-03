// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int solve(TreeNode* root) {
        if(root == NULL) return -2000;
        if(!root->left && !root->right) return root->val;

        int left = solve(root->left);
        int right = solve(root->right);
        int current = left + right + root->val;

        return max(max(left,right), current);
    }

public:
    int maxPathSum(TreeNode* root) {
        int sum = max(solve(root),root->val);
        return sum;
    }
};