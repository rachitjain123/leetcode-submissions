/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode *root, vector<int> &v)
    {
        if(root==NULL)
            return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>in_order;
        inOrder(root,in_order);
        return in_order;
    }
};