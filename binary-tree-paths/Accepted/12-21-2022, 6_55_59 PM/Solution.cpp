// https://leetcode.com/problems/binary-tree-paths

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
    void findPaths(vector<string>& paths, TreeNode* root, string path) {
        if(!root->left && !root->right) {
            paths.push_back(path);
            return;
        }

        if(root->left) findPaths(paths, root->left, path + "->" + to_string(root->left->val));
        if(root->right) findPaths(paths, root->right, path + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(!root) return paths;
        
        findPaths(paths, root, to_string(root->val));
        return paths;
    }
};