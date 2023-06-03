// https://leetcode.com/problems/balanced-binary-tree

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
    int heightBST(TreeNode *root) {
        if(root == NULL) return 0;
        int lh = heightBST(root->left);
        int rh = heightBST(root->right);
        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        bool isLeft = isBalanced(root->left);
        bool isRight = isBalanced(root->right);

        bool isItself = abs(heightBST(root->left) - heightBST(root->right)) <= 1;

        return isLeft && isRight && isItself;
    }
};