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
    TreeNode *deleteLeaves(TreeNode *root, int target)
    {
        if(root==NULL)
            return NULL;
        root->left=deleteLeaves(root->left,target);
        root->right=deleteLeaves(root->right,target);
        if(root->val==target && root->left==NULL && root->right==NULL)
            root=NULL;
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return deleteLeaves(root,target);
    }
};