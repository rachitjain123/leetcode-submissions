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
    TreeNode *res;
    int maxDepth;
    int getDepth(TreeNode *root, int depth)
    {
        if(root==NULL)
            return INT_MIN;
        int leftSubTreeDepth = getDepth(root->left,depth+1);
        int rightSubTreeDepth = getDepth(root->right,depth+1);
        
        int curNodeDepth = max(depth,max(leftSubTreeDepth,rightSubTreeDepth));
        
        if(leftSubTreeDepth == rightSubTreeDepth && curNodeDepth>=maxDepth)
        {
            res=root;
            maxDepth = curNodeDepth;
        }
        return curNodeDepth;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth = 0;
        getDepth(root,0);
        return res;
    }
};
