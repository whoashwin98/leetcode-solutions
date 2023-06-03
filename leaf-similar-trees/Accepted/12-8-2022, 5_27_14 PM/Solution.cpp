// https://leetcode.com/problems/leaf-similar-trees

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
    void inorder(TreeNode *root, vector<int>& ans) {
        if(root == NULL) return;
        inorder(root->left, ans);
        if(root->left == NULL && root->right == NULL) ans.push_back(root->val);
        inorder(root->right, ans);
    }


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) return false;
        
        vector<int> ans1, ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);

        if(ans1.size() != ans2.size()) return false;
        for(int i=0; i<ans1.size(); i++) {
            if(ans1[i] != ans2[i]) return false;
        }
        return true;
    }
};