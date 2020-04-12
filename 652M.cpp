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
    string getDuplicateTrees(TreeNode *root, map<string,int> &identifiers,vector<TreeNode *> &duplicates)
    {
        if(root==NULL)
            return "NULL";
        string leftId=getDuplicateTrees(root->left,identifiers,duplicates);
        string rightId=getDuplicateTrees(root->right,identifiers,duplicates);
        string id = leftId+rightId+to_string(root->val);
        if(identifiers.find(id) == identifiers.end())
            identifiers[id]=1;
        else if(identifiers[id]<=1)
        {
            duplicates.push_back(root);
            identifiers[id]=identifiers[id]+1;
        }
        return id;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int>identifiers;
        vector<TreeNode *> duplicates;
        getDuplicateTrees(root,identifiers,duplicates);
        return duplicates;
    }
};