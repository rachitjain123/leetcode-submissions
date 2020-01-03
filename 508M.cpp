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
    int sumTree(unordered_map<int,int> &mp, TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int sumSubTree=root->val+sumTree(mp,root->left)+sumTree(mp,root->right);
        mp[sumSubTree]++;
        return sumSubTree;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        sumTree(mp,root);
        int maxi=-1;
        vector<int>v;
        for(auto x:mp)
            maxi=max(maxi,x.second);
        for(auto x:mp)
        {
            if(x.second==maxi)
                v.push_back(x.first);
        }
        return v;
    }
};