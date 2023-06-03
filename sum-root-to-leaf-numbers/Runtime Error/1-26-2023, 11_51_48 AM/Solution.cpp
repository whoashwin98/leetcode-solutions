// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void findNums(TreeNode* root, string num, vector<int>& nums) {
        if(!root->left && !root->right) {
            num = num + to_string(root->val);
            cout << num << ", ";
            nums.push_back(stoi(num));
            return;
        }

        num = num + to_string(root->val);
        findNums(root->left, num, nums);
        findNums(root->right, num, nums);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        
        string num = "";
        vector<int> nums;
        findNums(root,num,nums);

        int sum = 0;
        for(int n: nums) sum = sum+n;
        return sum;
    }
};