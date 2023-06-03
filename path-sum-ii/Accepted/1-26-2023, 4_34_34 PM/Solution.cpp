// https://leetcode.com/problems/path-sum-ii

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
    bool checkSum(vector<int> nums, int target) {
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        return sum == target;
    }

    void solve(TreeNode* root, int target, vector<vector<int>>& paths, vector<int>& path) {
        if(root == NULL) return;
        

        path.push_back(root->val);
        solve(root->left, target, paths, path);
        solve(root->right, target, paths, path);
        
        if(!root->left && !root->right && checkSum(path, target)) paths.push_back(path);
        
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        solve(root,targetSum,paths,path);
        return paths;
    }
};