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
    int getMaxAncestorDiff(TreeNode *root,int min_val, int max_val)
    {
        if(root==NULL)
            return 0;
        int lMax=getMaxAncestorDiff(root->left,min(root->val,min_val),max(root->val,max_val));
        int rMax=getMaxAncestorDiff(root->right,min(root->val,min_val),max(root->val,max_val));
        int curNodeMax=max(abs(root->val-min_val),abs(root->val-max_val));
        return max(curNodeMax,max(lMax,rMax));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return getMaxAncestorDiff(root,root->val,root->val);
    }
};