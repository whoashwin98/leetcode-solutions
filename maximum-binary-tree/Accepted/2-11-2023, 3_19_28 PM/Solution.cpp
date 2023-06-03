// https://leetcode.com/problems/maximum-binary-tree

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
class compare {
    public: 
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.first < b.first;
    }
};

class Solution {
public:
    int findIndex(vector<int> nums, int s, int e) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(int i=s; i<=e; i++) pq.push({nums[i],i});
        return pq.top().second;
    }

    TreeNode* buildTree(vector<int>& nums, int s, int e) {
        if(s > e) return NULL;
        int idx = findIndex(nums, s, e);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = buildTree(nums, s, idx-1);
        root->right = buildTree(nums, idx+1, e);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        return buildTree(nums, s, e);
    }
};