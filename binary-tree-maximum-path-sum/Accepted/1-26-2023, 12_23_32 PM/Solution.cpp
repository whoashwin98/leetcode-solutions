// https://leetcode.com/problems/binary-tree-maximum-path-sum

class Solution {
    int solve(TreeNode* root, int& maxSum) {
        if(root == NULL) return 0;

        int left = max(solve(root->left, maxSum),0);
        int right = max(solve(root->right, maxSum),0);
        maxSum = max(maxSum, left + right + root->val);

        return max(left+root->val, right+root->val);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int dummy = solve(root, maxSum);
        return maxSum;
    }
};