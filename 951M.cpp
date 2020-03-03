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
    bool checkFlip(TreeNode *root1, TreeNode *root2)
    {
        if(root1==NULL && root2 ==NULL)
            return true;
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
            return false;
        if(root1->val != root2->val)
            return false;
        return (checkFlip(root1->left,root2->right) && checkFlip(root1->right,root2->left))
            || (checkFlip(root1->left,root2->left) && checkFlip(root1->right,root2->right));
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return checkFlip(root1,root2);
    }
};