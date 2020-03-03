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
    void getInorder(TreeNode *root, vector<int> &inorder)
    {
        if(root==NULL)
            return;
        getInorder(root->left,inorder);
        inorder.push_back(root->val);
        getInorder(root->right,inorder);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>inorder1,inorder2,merge_list;
        getInorder(root1,inorder1);
        getInorder(root2,inorder2);
        int i=0,j=0;
        while(i<inorder1.size() || j<inorder2.size())
        {
            if(i>=inorder1.size())
                merge_list.push_back(inorder2[j++]);
            else if(j>=inorder2.size())
                merge_list.push_back(inorder1[i++]);
            else if(inorder1[i]<inorder2[j])
                merge_list.push_back(inorder1[i++]);
            else
                merge_list.push_back(inorder2[j++]);
        }
        return merge_list;
    }
};