// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    struct qItem
{
   TreeNode *node;
   int depth;
};
public:
    int minDepth(TreeNode* root) {
   if (root == NULL)
        return 0;
 
    // Create an empty queue for level order traversal
    queue<qItem> q;
 
    // Enqueue Root and initialize depth as 1
    qItem qi = {root, 1};
    q.push(qi);
 
    // Do level order traversal
    while (q.empty() == false)
    {
       // Remove the front queue item
       qi = q.front();
       q.pop();
 
       // Get details of the remove item
       TreeNode *node = qi.node;
       int depth = qi.depth;
 
       // If this  is the first leaf node seen so far
       // Then return its depth as answer
       if (node->left == NULL && node->right == NULL)
          return depth;
 
       // If left subtree is not NULL, add it to queue
       if (node->left != NULL)
       {
          qi.node  = node->left;
          qi.depth = depth + 1;
          q.push(qi);
       }
 
       // If right subtree is not NULL, add it to queue
       if (node->right != NULL)
       {
          qi.node  = node->right;
          qi.depth = depth+1;
          q.push(qi);
       }
    }
    return 0;
    }
};