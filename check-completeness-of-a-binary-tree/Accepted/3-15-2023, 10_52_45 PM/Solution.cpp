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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> tree;
        tree.push_back(root);
        int i = 0;

        // this loop keeps running till the first NULL element is encountered
        while (i < tree.size() && tree[i]) {
            tree.push_back(tree[i]->left);
            tree.push_back(tree[i]->right);
            i++;
        }

        // this will never run if a tree is CBT
        // this condition will fail if there is any element existing after NULL has occurred 
        // which means the tree is not a CBT
        while (i < tree.size() && !tree[i])
            i++;
        
        // this will be true only when CBT condition is true
        return i == tree.size();
    }
};