/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int getNumGoodNodes(TreeNode *root, int max_value)
    {
        if(root==NULL)
            return 0;
        int num_good_nodes=0;
        if(root->val>=max_value) num_good_nodes++;
        return num_good_nodes 
            + getNumGoodNodes(root->left,max(max_value,root->val)) 
            + getNumGoodNodes(root->right,max(max_value,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        return getNumGoodNodes(root,INT_MIN);
    }
};