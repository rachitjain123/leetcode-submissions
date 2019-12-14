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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<vector<int> >level_order;
        if(root==NULL)
            return level_order;
        int level_num=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>level;
            level_num=1-level_num;
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
            if(level_num%2==0)
                reverse(level.begin(),level.end());
            level_order.push_back(level);
        }
        return level_order;
    }
};