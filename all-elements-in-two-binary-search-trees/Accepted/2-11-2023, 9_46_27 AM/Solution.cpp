// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    void inorder(TreeNode* root, vector<int>& in) {
        if(root == NULL) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    void merge(vector<int> list1, vector<int> list2, vector<int>& ans) {
        int a = 0, b = 0;
        int m = list1.size(), n = list2.size();

        while(a < m && b < n) {
            if(list1[a] < list2[b]) {
                ans.push_back(list1[a++]);
            }

            else ans.push_back(list2[b++]);
        }

        while(a < m) {
            ans.push_back(list1[a++]);
        }

        while(b < n) {
            ans.push_back(list2[b++]);
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;

        inorder(root1, list1);
        inorder(root2, list2);

        vector<int> ans;
        merge(list1, list2, ans);
        return ans;
    }
};