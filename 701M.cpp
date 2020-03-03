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
    TreeNode *insert(TreeNode *root, int val)
    {
        if(root==NULL)
            root=new TreeNode(val);
        else if(val<=root->val)
            root->left=insert(root->left,val);
        else
            root->right=insert(root->right,val);
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root,val);
    }
};