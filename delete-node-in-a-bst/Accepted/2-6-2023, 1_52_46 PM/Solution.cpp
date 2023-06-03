// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* maxVal(TreeNode* root) {
        TreeNode* temp = root;
        while(temp->right) temp = temp->right;
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) {
            // zero child case
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // one child case
            if(root->left && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            if(root->right && root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // two children case
            if(root->left && root->right) {
                // max from left sub-tree (find in-order predecessor)
                // min from right sub-tree (find in-order successor)
                int maxi = maxVal(root->left)->val;
                root->val = maxi;
                root->left = deleteNode(root->left,maxi);
            }
        }  

        else if(root->val > val) {
            root->left = deleteNode(root->left, val);
            return root;
        }

        root->right = deleteNode(root->right, val);
        return root;
    }
};