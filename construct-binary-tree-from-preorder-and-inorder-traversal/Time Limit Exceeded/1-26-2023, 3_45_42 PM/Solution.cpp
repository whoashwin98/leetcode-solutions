// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* solve(vector<int> preorder, vector<int> inorder, int& index, int istart, int iend, unordered_map<int,int> mp) {
        // base case
        if(index >= preorder.size() || istart > iend) return NULL;

        int element = preorder[index++];
        
        int pos = (mp.find(element) != mp.end()) ? mp[element] : -1;

        TreeNode* root = new TreeNode(element);
        root->left = solve(preorder, inorder, index, istart, pos-1, mp);
        root->right = solve(preorder, inorder, index, pos+1, iend, mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        unordered_map<int,int> mp;

        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        
        TreeNode* root = solve(preorder, inorder, preOrderIndex, 0, n-1, mp);
        return root;
    }
};