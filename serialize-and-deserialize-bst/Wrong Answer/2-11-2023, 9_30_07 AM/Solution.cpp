// https://leetcode.com/problems/serialize-and-deserialize-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void inorder(TreeNode* root, string& ans) {
        if(root == NULL) return;
        inorder(root->left, ans);
        string num = to_string(root->val);
        for(char ch : num) ans.push_back(ch);
        ans.push_back('$'); // separator
        inorder(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        inorder(root, ans);
        return ans;
    }

    vector<int> convertToArray(string data) {
        if(data == "") return {};
        vector<int> ans;
        string num = "";
        for(int i=0; i<data.size(); i++) {
            if(data[i] == '$') {
                ans.push_back(stoi(num));
                num = "";
            }
            else num.push_back(data[i]);
        }
        return ans;
    }
    
    TreeNode* constructBST(int s, int e, vector<int>& in) {
        if(s > e) return NULL;
        int mid = (s+e) / 2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = constructBST(s, mid-1, in);
        root->right = constructBST(mid+1, e, in);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> in = convertToArray(data);
        return constructBST(0, in.size()-1, in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;