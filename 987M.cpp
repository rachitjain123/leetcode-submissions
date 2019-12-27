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
    void getVericalOrder(TreeNode* root, int height, map<int,vector<pair<int,int> > > &mp)
    {
        queue<pair<TreeNode *, int> > q;
        q.push({root,0});
        int h1=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *rt=q.front().first;
                int ht=q.front().second;
                q.pop();
                mp[ht].push_back({h1,rt->val});
                if(rt->left!=NULL)
                    q.push({rt->left,ht-1});
                if(rt->right!=NULL)
                    q.push({rt->right,ht+1});
            }
            h1++;
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int> > > mp;
        getVericalOrder(root,0,mp);
        vector<vector<int> >vertical_traversal;
        for(auto x:mp)
        {
            sort(x.second.begin(),x.second.end());
            vector<int>tmp;
            for(int i=0;i<x.second.size();i++)
                tmp.push_back(x.second[i].second);
            vertical_traversal.push_back(tmp);
        }
        return vertical_traversal;
    }
};