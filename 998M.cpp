// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// Technique 1
// class Solution {
//     int findMax(vector<int> &nums, int low, int high)
//     {
//         int max_no=-INT_MAX;
//         int ind=low;
//         for(int i=low;i<=high;i++)
//         {
//             if(nums[i]>max_no)
//             {
//                 max_no=nums[i];
//                 ind=i;
//             }
//         }
//         return ind;
//     }
//     TreeNode *construct(int low, int high, vector<int> &nums)
//     {
//         if(low>high)
//             return NULL;
//         int maxInd=findMax(nums,low,high);
//         TreeNode *rt=new TreeNode(nums[maxInd]);
//         rt->left=construct(low,maxInd-1,nums);
//         rt->right=construct(maxInd+1,high,nums);
//         return rt;
//     }
//     void getInorder(TreeNode* root, vector<int> &inorder)
//     {
//         if(root==NULL)
//             return;
//         getInorder(root->left,inorder);
//         inorder.push_back(root->val);
//         getInorder(root->right,inorder);
//     }
// public:
//     TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
//         vector<int>inorder;
//         getInorder(root,inorder);
//         inorder.push_back(val);
//         return construct(0,inorder.size()-1,inorder);
//     }
// };

// Technique 2 (Much better)
class Solution {
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        if(root==NULL || val>root->val)
        {
            TreeNode *tmp=new TreeNode(val);
            tmp->left=root;
            return tmp;
        }
        root->right=insertIntoMaxTree(root->right,val);
        return root;
    }
};