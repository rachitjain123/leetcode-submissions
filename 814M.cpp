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
    bool btreePrune(TreeNode *root)
    {
        if(root==NULL)
            return false;
        bool l=btreePrune(root->left);
        bool r=btreePrune(root->right);
        if(!l) root->left=NULL;
        if(!r) root->right=NULL;
        return root->val == 1 || l || r;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return btreePrune(root) ? root : NULL;
    }
};