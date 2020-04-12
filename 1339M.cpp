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
    int getTotal(TreeNode *root,vector<int> &subTreeSum)
    {
        if(root==NULL)
            return 0;
        int lSum=getTotal(root->left,subTreeSum);
        int rSum=getTotal(root->right,subTreeSum);
        subTreeSum.push_back(lSum+rSum+root->val);
        return lSum+rSum+root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        vector<int> subTreeSum;
        int totalVal=getTotal(root,subTreeSum);
        long long int maxVal=0;
        long long int mod=(long long int)1e9+7;
        for(int i=0;i<subTreeSum.size();i++)
        {
            long long int val=(long long int)subTreeSum[i]*(totalVal-subTreeSum[i]);
            if(maxVal<val)
                maxVal=val;
        }
        return maxVal%mod;
    }
};