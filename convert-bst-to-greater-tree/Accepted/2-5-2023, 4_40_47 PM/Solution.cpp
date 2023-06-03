// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    void inorderSum(TreeNode* root, int& sum) {
        if(root == NULL) return;
        inorderSum(root->left, sum);
        sum += root->val;
        inorderSum(root->right, sum);
    }
    
    void update(TreeNode*& root, int& sum) {
        if(root == NULL) return;
        update(root->left, sum);
        int curr = root->val;
        root->val = sum;
        sum -= curr;
        update(root->right, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inorderSum(root, sum);
        update(root, sum);
        return root;
    }
};