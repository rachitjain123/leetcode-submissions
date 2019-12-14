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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<pair<TreeNode *,int> >q;
        map<int,bool>mp;
        q.push({root,0});
        vector<int>sideView;
        if(root==NULL)
            return sideView;
        while(!q.empty())
        {
            TreeNode *tmp=q.front().first;
            int level=q.front().second;
            if(!mp[level])
            {
                mp[level]=true;
                sideView.push_back(tmp->val);
            }
            q.pop();
            if(tmp->right!=NULL)
                q.push({tmp->right,level+1});
            if(tmp->left!=NULL)
                q.push({tmp->left,level+1});
        }
        return sideView;
    }
};

// Another good solution(not requiring map)

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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<TreeNode *>q;
        vector<int>sideView;
        if(root==NULL)
            return sideView;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            TreeNode *prev=NULL;
            for(int i=0;i<size;i++)
            {
                TreeNode *tmp=q.front();
                q.pop();
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
                prev=tmp;
            }
            sideView.push_back(prev->val);
        }
        return sideView;
    }
};