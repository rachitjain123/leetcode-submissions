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
    bool checkValid(TreeNode *root, long min_val, long max_val)
    {
        if(root==NULL)
            return true;
        if(root->val<=min_val || root->val>=max_val)
            return false;
        return checkValid(root->left,min_val,root->val) && checkValid(root->right,root->val,max_val);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int min_val = -1e18;
        long long int max_val = 1e18;
        return checkValid(root,min_val,max_val);
    }
};