// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    bool isValidPath(vector<int> path, int value) {
        for(int i=0; i<path.size(); i++) {
            if(path[i] > value) return false;
        }
        return true;
    }

    void solve(TreeNode* root, vector<int>& path, int& ans) {
        if(root == NULL) return;
        path.push_back(root->val);
        solve(root->left, path, ans);
        solve(root->right, path, ans);
        if(isValidPath(path, root->val)) ans = ans+1;
        path.pop_back();
    }

public:
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        vector<int> path;
        solve(root, path, ans);
        return ans;
    }
};