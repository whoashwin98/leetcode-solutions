// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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

    TreeNode* solve(vector<int> postorder, vector<int> inorder, int& index, int istart, int iend) {
        // base case
        if(index < 0 || istart > iend) return NULL;

        int element = postorder[index--];
        int pos = findPos(inorder,element);

        TreeNode* root = new TreeNode(element);
        root->right = solve(postorder, inorder, index, pos+1, iend);
        root->left = solve(postorder, inorder, index, istart, pos-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIndex = postorder.size()-1;
        TreeNode* root = solve(postorder,inorder,postOrderIndex,0,inorder.size()-1);
        return root;
    }
};