// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void findNums(TreeNode* root, int num, int& ans) {
        if(root == NULL) return;

        if(!root->left && !root->right) {
            num = num*10 + root->val;
            ans += num;
            return;
        }

        num = num*10 + root->val;
        findNums(root->left, num, ans);
        findNums(root->right, num, ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        
        int num = 0;
        int ans = 0;
        findNums(root,num,ans);
        return ans;
    }
};