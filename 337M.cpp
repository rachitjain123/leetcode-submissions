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
    void maxMoney(TreeNode *root,  map<TreeNode *,int> & dp1,  map<TreeNode *,int> &dp2)
    {
        int sum1=0,sum2=0;
        if(root==NULL)
            return;
        maxMoney(root->left,dp1,dp2);
        maxMoney(root->right,dp1,dp2);
        if(root->left!=NULL)
        {
            sum1+=dp2[root->left];
            sum2+=max(dp1[root->left],dp2[root->left]);
        }
        if(root->right!=NULL)
        {
            sum1+=dp2[root->right];
            sum2+=max(dp1[root->right],dp2[root->right]);
        }
        dp1[root]=sum1+root->val;
        dp2[root]=sum2;
            
    }
    public:
    int rob(TreeNode* root) {
        map<TreeNode *,int>dp1;
        map<TreeNode *,int>dp2;
        maxMoney(root,dp1,dp2);
        return max(dp1[root],dp2[root]);
    }
};



// constant space
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
    pair<int,int> maxMoney(TreeNode *root)
    {
        int sum1=0,sum2=0;
        if(root==NULL)
            return {0,0};
        pair<int,int> rob_left=maxMoney(root->left);
        pair<int,int> rob_right=maxMoney(root->right);
        
        int rob=rob_left.second+rob_right.second+root->val;
        int not_rob=max(rob_left.first,rob_left.second)+max(rob_right.first, rob_right.second);;
        return {rob,not_rob};
            
    }
    public:
    int rob(TreeNode* root) {
        pair<int,int> rob=maxMoney(root);
        return max(rob.first,rob.second);
    }
};