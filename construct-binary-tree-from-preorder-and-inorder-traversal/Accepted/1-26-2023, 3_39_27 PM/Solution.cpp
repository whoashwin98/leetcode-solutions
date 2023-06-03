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
    int findPos(vector<int> inorder, int ele) {
        for(int i=0; i<inorder.size(); i++) {
            if(inorder[i] == ele) return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int> preorder, vector<int> inorder, int& index, int istart, int iend) {
        // base case
        if(index >= preorder.size() || istart > iend) return NULL;

        int element = preorder[index++];
        int pos = findPos(inorder,element);

        TreeNode* root = new TreeNode(element);
        root->left = solve(preorder, inorder, index, istart, pos-1);
        root->right = solve(preorder, inorder, index, pos+1, iend);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        TreeNode* root = solve(preorder, inorder, preOrderIndex, 0, n-1);
        return root;
    }
};