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
    bool removeNodes(TreeNode *root, TreeNode *parent,int limit,int sumVal)
    {
        if(root==NULL)
        {
            if(sumVal>=limit)
                return true;
            return false;
        }
        bool isLeftLess=removeNodes(root->left,root,limit,sumVal+root->val);
        bool isRightLess=removeNodes(root->right,root,limit,sumVal+root->val);
        if(isLeftLess||isRightLess)
            return true;
        if(parent->left==root)
            parent->left=NULL;
        if(parent->right==root)
            parent->right=NULL;
        return false;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        removeNodes(root,NULL,limit,0);
        return root;
    }
};