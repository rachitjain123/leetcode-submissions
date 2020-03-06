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
    void preOrder(TreeNode *root, vector<int> &preOrder_traversal)
    {
        if(root==NULL)
            return;
        preOrder_traversal.push_back(root->val);
        preOrder(root->left,preOrder_traversal);
        preOrder(root->right,preOrder_traversal);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder_traversal;
        preOrder(root,preOrder_traversal);
        return preOrder_traversal;
    }
};