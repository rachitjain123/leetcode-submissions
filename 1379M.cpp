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
    TreeNode* findNode(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if(original == NULL)
            return NULL;
        if(original == target)
            return cloned;
        TreeNode *isTargetL = findNode(original->left,cloned->left,target);
        TreeNode *isTargetR = findNode(original->right,cloned->right,target);
        if(isTargetL != NULL)
            return isTargetL;
        if(isTargetR != NULL)
            return isTargetR;
        return NULL;
        
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return findNode(original, cloned, target);
    }
};