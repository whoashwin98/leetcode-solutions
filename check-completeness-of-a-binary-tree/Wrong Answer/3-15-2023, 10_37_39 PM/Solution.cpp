// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    void traverse(TreeNode* root, vector<int>& tree, int& count) {
        if(root == NULL) {
            tree.push_back(-1);
            return;
        }

        if(!root->left && !root->right) {
            tree.push_back(root->val);
            count++;
            return;
        }

        tree.push_back(root->val);
        count++;
        traverse(root->left, tree, count);
        traverse(root->right, tree, count);
    }

    bool isCompleteTree(TreeNode* root) {
        vector<int> tree;
        int count = 0;
        traverse(root, tree, count);
        
        for(int i=0; i<count; i++) {
            if(tree[i] == -1) return false;
        }

        return true;
    }
};