// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode* solve(vector<int> preorder, vector<int> inorder, int& index, int istart, int iend) {
        // base case
        if(index >= preorder.size() || istart > iend) return NULL;
        int element = preorder[index++];
        int pos = lower_bound(inorder.begin(), inorder.end(), element) - inorder.begin();
        TreeNode* root = new TreeNode(element);
        root->left = solve(preorder, inorder, index, istart, pos-1);
        root->right = solve(preorder, inorder, index, pos+1, iend);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        TreeNode* root = solve(preorder, inorder, preOrderIndex, 0, n-1);
        return root;
    }
};

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