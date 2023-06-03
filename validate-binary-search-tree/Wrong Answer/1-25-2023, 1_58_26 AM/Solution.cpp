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
    bool isValidUtil(TreeNode* root, int mini, int maxi) {
        if(!root) return true;

        bool left = isValidUtil(root->left, mini, root->val);
        bool right = isValidUtil(root->right, root->val, maxi);

        return left && right && (root->val > mini && root->val < maxi);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidUtil(root, INT_MIN, INT_MAX);
    }
};