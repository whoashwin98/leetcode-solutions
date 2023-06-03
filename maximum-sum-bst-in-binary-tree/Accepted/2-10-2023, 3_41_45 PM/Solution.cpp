// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree

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
class Node {
    public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

class Solution {
public:
    Node solve(TreeNode* root, int& ans) {
        if(root == NULL) {
            return {INT_MIN, INT_MAX, true, 0};
        }

        Node left = solve(root->left, ans);
        Node right = solve(root->right, ans);

        Node curr;

        curr.sum = left.sum + right.sum + root->val;
        curr.maxi = max(root->val, right.maxi);
        curr.mini = min(root->val, left.mini);

        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini)) curr.isBST = true;
        else curr.isBST = false;

        if(curr.isBST) ans = max(ans, curr.sum);
        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        Node temp = solve(root, maxSum);
        return maxSum;
    }
};