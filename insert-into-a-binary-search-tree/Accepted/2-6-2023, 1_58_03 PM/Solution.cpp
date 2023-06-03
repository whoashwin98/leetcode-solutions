// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if root is NULL then first node in BST
        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }

        // insert in right sub-tree if data greater than root
        if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } 
        // if data smaller than root insert in left sub-tree
        else {
            root->left = insertIntoBST(root->left, val);    
        }

        // return the root (has the new BST with inserted node)
        return root;
    }
};