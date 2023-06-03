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
    
    void serialize(TreeNode* root, string& result) {
        if (root == nullptr) return;
        result += to_string(root->val) + ",";
        serialize(root->left, result);
        serialize(root->right, result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        queue<string> q;
        stringstream ss(data);
        string s;
        while (getline(ss, s, ',')) {
            q.push(s);
        }
        return deserialize(q, INT_MIN, INT_MAX);
    }
    
    TreeNode* deserialize(queue<string>& q, int lower, int upper) {
        if (q.empty()) return nullptr;
        int val = stoi(q.front());
        if (val < lower || val > upper) return nullptr;
        q.pop();
        TreeNode* root = new TreeNode(val);
        root->left = deserialize(q, lower, val);
        root->right = deserialize(q, val, upper);
        return root;
    }
};
