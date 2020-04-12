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
    int preIndex;
    TreeNode *getTree(vector<int> &inorder, vector<int> &preorder, int low, int high)
    {
        if(low>high)
            return NULL;
        TreeNode *root=new TreeNode(preorder[preIndex]);
        int searchIndex;
        for(int i=low;i<high;i++)
        {
            if(inorder[i]==root->val)
            {
                searchIndex=i;
                break;
            }
        }
        preIndex++;
        root->left=getTree(inorder,preorder,low,searchIndex-1);
        root->right=getTree(inorder,preorder,searchIndex+1,high);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex=0;
        return getTree(inorder,preorder,0,preorder.size()-1);
    }
};