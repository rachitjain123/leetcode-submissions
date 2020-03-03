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
    int findMax(vector<int> &nums, int low, int high)
    {
        int max_no=-INT_MAX;
        int ind=low;
        for(int i=low;i<=high;i++)
        {
            if(nums[i]>max_no)
            {
                max_no=nums[i];
                ind=i;
            }
        }
        return ind;
    }
    TreeNode *construct(int low, int high, vector<int> &nums)
    {
        if(low>high)
            return NULL;
        int maxInd=findMax(nums,low,high);
        TreeNode *rt=new TreeNode(nums[maxInd]);
        rt->left=construct(low,maxInd-1,nums);
        rt->right=construct(maxInd+1,high,nums);
        return rt;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(0,nums.size()-1,nums);
    }
};