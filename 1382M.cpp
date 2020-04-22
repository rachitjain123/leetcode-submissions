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
    void getTraversal(TreeNode *root, vector<int> &inorder)
    {
        if(root==NULL)
            return;
        getTraversal(root->left,inorder);
        inorder.push_back(root->val);
        getTraversal(root->right,inorder);
    }
    TreeNode *getBalancedBST(vector<int> &inorder,int low, int high)
    {
        if(low>high)
            return NULL;
        int mid=(low+high)/2;
        TreeNode *root=new TreeNode(inorder[mid]);
        root->left=getBalancedBST(inorder,low,mid-1);
        root->right=getBalancedBST(inorder,mid+1,high);
        return root;
        
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        getTraversal(root,inorder);
        return getBalancedBST(inorder,0,inorder.size()-1);
    }
};