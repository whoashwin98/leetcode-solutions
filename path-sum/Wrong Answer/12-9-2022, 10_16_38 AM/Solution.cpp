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
    void traversal(TreeNode* root, int target, unordered_set<int>& ans, int& sum) {
        if(root == NULL) return;

        sum += root->val;
        ans.insert(sum);
        traversal(root->left, target, ans, sum);
        traversal(root->right, target, ans, sum);
        sum -= root->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        unordered_set<int> ans;
        int sum = 0;
        traversal(root, targetSum, ans, sum);
        if(ans.find(targetSum) == ans.end()) return false;
        else return true;
    }
};