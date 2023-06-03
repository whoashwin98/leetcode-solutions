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
    void findPaths(TreeNode* root, string& ans, vector<string>& paths) {
        if(root == NULL) return;

        ans+=to_string(root->val);

        if(root->left==NULL && root->right==NULL ){
            paths.push_back(ans);
        }

        ans+="->";

        findPaths(root->left,ans,paths);
        findPaths(root->right,ans,paths);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string ans = "";
        findPaths(root,ans,paths);
        return paths;
    }
};