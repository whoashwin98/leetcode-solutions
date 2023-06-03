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
    void traversal(TreeNode* root, int target, set<int>& ans, int& sum) {
        if(root == NULL) return;

        sum += root->val;
        if(root->left == NULL && root->right == NULL) ans.insert(sum);
        traversal(root->left, target, ans, sum);
        traversal(root->right, target, ans, sum);
        sum -= root->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        set<int> ans;
        int sum = 0;
        traversal(root, targetSum, ans, sum);
        for(int num : ans) cout << num << " ";
        if(ans.find(targetSum) == ans.end()) return false;
        else return true;
    }
};