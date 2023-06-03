// https://leetcode.com/problems/serialize-and-deserialize-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serialize(root, result);
        return result;
    }
    
    // storing preorder traversal for the given tree
    void serialize(TreeNode* root, string& result) {
        if (root == NULL) return;
        result += to_string(root->val) + ",";
        serialize(root->left, result);
        serialize(root->right, result);
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        // using a queue to process the nodes one by one
        queue<string> q;
        stringstream ss(data);
        string s;
        while (getline(ss, s, ',')) {
            q.push(s);
        }
        return deserialize(q, INT_MIN, INT_MAX);
    }
    
    // using the range method to construct BST as and when integers are fed to it.

    TreeNode* deserialize(queue<string>& q, int lower, int upper) {
        if (q.empty()) return NULL;
        // get the front value and convert to integer
        int val = stoi(q.front());
        // if out of range that means we have to insert somewhere else
        // so we return NULL for this particular link
        if (val < lower || val > upper) return NULL;

        // we have found a valid place for val to be inserted
        q.pop();
        // create a new node with this value, and make recursive calls for left and right
        TreeNode* root = new TreeNode(val);
        // left values will have range from lower limit to val
        root->left = deserialize(q, lower, val);
        // right values will have range from val to upper limit
        root->right = deserialize(q, val, upper);
        return root;
    }
};
