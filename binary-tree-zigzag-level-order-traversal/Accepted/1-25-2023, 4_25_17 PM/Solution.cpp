// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        if(root == NULL) return ans;

        q.push(root);
        q.push(NULL);
        bool ltr = true;
        vector<int> level;

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL) {
                if(!ltr) reverse(level.begin(), level.end());
                ans.push_back(level);
                ltr = !ltr;
                level.clear();
                if(!q.empty()) q.push(NULL);
            }

            else {
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};