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
    int maxZZ(TreeNode *root, int lenPath, int dir)
    {
        if(root==NULL)
            return lenPath;
        if(dir==0)
            return max(maxZZ(root->left,1,dir),maxZZ(root->right,lenPath+1,1-dir));
        return max(maxZZ(root->right,1,dir),maxZZ(root->left,lenPath+1,1-dir));
    }
public:
    int longestZigZag(TreeNode* root) {
        if(root==NULL)
            return 0;
        return max(maxZZ(root->left,1,0),maxZZ(root->right,1,1))-1;
    }
};