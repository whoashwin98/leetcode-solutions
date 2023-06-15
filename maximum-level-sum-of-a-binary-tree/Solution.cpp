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
class Solution
{
public:
    vector<pair<int, int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        int level = 1;
        int sum = 0;
        vector<pair<int, int>> ans;

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            // level complete;
            if (temp == NULL)
            {
                ans.push_back({sum, level});
                level++;
                sum = 0;
                if (!q.empty())
                    q.push(NULL);
            }

            else
            {
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return ans;
    }

    int maxLevelSum(TreeNode *root)
    {
        // perform a level order traversal, and store the sum
        vector<pair<int, int>> levelSums = levelOrder(root);

        // get the maximum value and the level
        int maxSum = INT_MIN;
        int level = 0;
        for (auto it : levelSums)
        {
            if (it.first > maxSum)
            {
                maxSum = it.first;
                level = it.second;
            }
        }

        return level;
    }
};