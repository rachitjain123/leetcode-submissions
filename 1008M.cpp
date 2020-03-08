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
    int index;
    TreeNode *constructBST(vector<int> &preorder,int min_val, int max_val)
    {
        if(index>=preorder.size()||preorder[index]<min_val||preorder[index]>max_val)
            return NULL;
        TreeNode *root=new TreeNode(preorder[index++]);
        root->left=constructBST(preorder,min_val,root->val);
        root->right=constructBST(preorder,root->val,max_val);
        return root;
        
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructBST(preorder,INT_MIN,INT_MAX);
    }
};