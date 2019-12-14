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
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<int>largest_values;
        if(root==NULL)
            return largest_values;
        while(!q.empty())
        {
            int sz=q.size();
            long long int row_max=-(long long int)(1e18);
            for(int i=0;i<sz;i++)
            {
                TreeNode *tmp=q.front();
                q.pop();
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
                if(tmp->val>row_max)
                    row_max=tmp->val;
            }
            largest_values.push_back(row_max);
        }
        return largest_values;
    }
};