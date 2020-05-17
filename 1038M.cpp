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
private:
    int sum=0;
    void getGreaterSumTree(TreeNode *root) {
        if(root==NULL)
            return;
        getGreaterSumTree(root->right);
        
        sum+=root->val;
        root->val=sum;
        
        getGreaterSumTree(root->left);
        
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        getGreaterSumTree(root);
        return root;
    }
};