// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildTree(ListNode* head, ListNode* tail) {
        if(head == tail) return NULL;

        ListNode* temp = head;
        ListNode* mid = head;

        while(temp != tail && temp->next != tail) {
            temp = temp->next->next;
            mid = mid->next;
        }

        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(head,mid);
        root->right = buildTree(mid->next,tail);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = buildTree(head, NULL);
        return root;
    }
};