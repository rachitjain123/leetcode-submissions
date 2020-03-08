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
    int xleft=0;
    int xright=0;
    int getSubTreeNodes(TreeNode *root, int x, bool isSeen)
    {
        if(root==NULL)
            return 0;
        if(root->val==x)
            isSeen=true;
        int numleftNodes = getSubTreeNodes(root->left,x,isSeen);
        int numrightNodes = getSubTreeNodes(root->right,x,isSeen);
        if(root->val==x)
        {
            xleft=numleftNodes;
            xright=numrightNodes;
        }
        if(isSeen)
            return numleftNodes + numrightNodes + 1;
        return 0;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        getSubTreeNodes(root,x,false);
        int maxi=max(max(xleft,xright),n-xleft-xright-1);
        if(maxi>n-maxi)
            return true;
        return false;
    }
};