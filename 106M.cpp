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
    int postIndex;
    TreeNode *getTree(vector<int> &inorder, vector<int> &postorder, int low, int high)
    {
        if(low>high)
            return NULL;
        TreeNode *root=new TreeNode(postorder[postIndex]);
        int searchIndex;
        for(int i=low;i<high;i++)
        {
            if(inorder[i]==root->val)
            {
                searchIndex=i;
                break;
            }
        }
        postIndex--;
        root->right=getTree(inorder,postorder,searchIndex+1,high);
        root->left=getTree(inorder,postorder,low,searchIndex-1);
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
        postIndex=postOrder.size()-1;
        return getTree(inOrder,postOrder,0,postOrder.size()-1);
    }
};