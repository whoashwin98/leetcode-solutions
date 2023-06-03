// https://leetcode.com/problems/diameter-of-binary-tree

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

    
// a faster way is to calculate both the height and diameter 
// during the recursion and return as a pair
// first slot of the pair stores diameter, second slot of the pair stores height
// takes O(n) time since only calls for calculating diameter are made
pair<int,int> diameterFast(TreeNode *root) {
    // if NULL node means both height and diameter are zero
    if(root == NULL) return make_pair(0,0);

    // get the answers for the left and right sub-trees recursively
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    // case - 1 : only in left subtree
    int a = left.first;
    // case - 2 : only in right subtree
    int b = right.first;
    // case - 3 : lies in both
    int c = left.second + right.second + 1;

    pair<int,int> ans;
    // calculate the diameter here (out of the three cases the maximum)
    ans.first = max(max(a,b),c);
    // also calculate the height of the subtree with current node as the root
    ans.second = max(left.second,right.second) + 1;
    return ans;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = diameterFast(root);
        return ans.first - 1;
    }
};