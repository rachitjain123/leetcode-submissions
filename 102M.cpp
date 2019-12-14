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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<vector<int> >level_order;
        if(root==NULL)
            return level_order;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>level;
            for(int i=0;i<sz;i++)
            {
                TreeNode *tmp=q.front();
                q.pop();
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
                level.push_back(tmp->val);
            }
            level_order.push_back(level);
        }
        return level_order;
    }
};