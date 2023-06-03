// https://leetcode.com/problems/path-sum

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
    bool traversal(TreeNode* root, int target, int& sum) {
        if(root == NULL) return false;
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == target) return true;
        if(traversal(root->left, target, sum)) return true;
        if(traversal(root->right, target, sum)) return true;
        sum -= root->val;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return traversal(root, targetSum, sum);
    }
};