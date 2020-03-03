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
    int inorder(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int sum1=inorder(root->left);
        int sum=0;
        if(root->val%2==0)
        {
            if(root->left!=NULL)
            {
                if(root->left->left!=NULL)
                    sum=sum+root->left->left->val;
                if(root->left->right!=NULL)
                    sum=sum+root->left->right->val;
            }
            if(root->right!=NULL)
            {
                if(root->right->left!=NULL)
                    sum=sum+root->right->left->val;
                if(root->right->right!=NULL)
                    sum=sum+root->right->right->val;
            }
        }
        int sum2=inorder(root->right);
        return sum1+sum2+sum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return inorder(root);
    }
};