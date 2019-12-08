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
    vector<int>adj[501];
    bool vis[501];
    void dfs(TreeNode *root, TreeNode *parent)
    {
        if(root==NULL)
            return;
        vis[root->val]=false;
        if(parent!=NULL)
        {
            adj[root->val].push_back(parent->val);
            adj[parent->val].push_back(root->val);
        }
        dfs(root->left,root);
        dfs(root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        dfs(root, NULL);
        queue<pair<int,int> >q;
        q.push({target->val,0});
        vector<int>val_nodes;
        vis[target->val]=true;
        while(!q.empty())
        {
            int src=q.front().first;
            int level=q.front().second;
            if(level==K)
                val_nodes.push_back(src);
            q.pop();
            for(int i=0;i<adj[src].size();i++)
            {
                if(vis[adj[src][i]]==false)
                {
                    q.push({adj[src][i],level+1});
                    vis[adj[src][i]]=true;
                }
            }
        }
        return val_nodes;
    }
};