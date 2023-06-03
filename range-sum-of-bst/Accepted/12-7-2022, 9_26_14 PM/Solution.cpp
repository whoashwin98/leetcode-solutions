// https://leetcode.com/problems/range-sum-of-bst

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
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> inor;
        inorder(root,inor);

        int li = lower_bound(inor.begin(), inor.end(), low) - inor.begin();
        int hi = lower_bound(inor.begin(), inor.end(), high) - inor.begin();

        int ans = 0;
        for(int i=li; i<=hi; i++) {
            ans += inor[i];
        }

        return ans;
    }
};