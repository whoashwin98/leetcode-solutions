// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void preorder(TreeNode* root, vector<int>& pre) {
        if(root == NULL) return;

        pre.push_back(root->val);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }

public:
    void flatten(TreeNode* root) {
        vector<int> pre;
        preorder(root,pre);

        TreeNode* node = root;
        for(int i=1; i<pre.size(); i++) {
            node->left = NULL;
            node->right = new TreeNode(pre[i]);
            node = node->right;
        }
    }
};