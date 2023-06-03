// https://leetcode.com/problems/find-duplicate-subtrees

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
    unordered_map<string, int> map;
    vector<TreeNode*> nodelist;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        recc(root);
        return nodelist;
    }
    
    string recc(TreeNode* root) {
        if (!root) {
            return "null";
        }
        
        string leftNodepath = recc(root->left);
        string rightNodepath = recc(root->right);
        
        // Hashmap will store the path of node as key and its freq is checked
        // that the same path string matches mimicking the same subtree
        string path = to_string(root->val) + ", " + leftNodepath + ", " + rightNodepath;
        
        map[path]++;
        
        if (map[path] == 2) {
            nodelist.push_back(root);
        }
        
        return path;
    }
};