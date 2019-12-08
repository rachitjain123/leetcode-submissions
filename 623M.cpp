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
    void insert(TreeNode* node, int val, int depth, int d)
    {
        if(node == NULL)
            return;
        if(depth == d-1)
        {
            TreeNode *t=node->left;
            node->left=new TreeNode(val);
            node->left->left=t;
            t=node->right;
            node->right=new TreeNode(val);
            node->right->right=t;
        }
        else
        {
            insert(node->left,val,depth+1,d);
            insert(node->right,val,depth+1,d);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {

        if(d==1)
        {
            TreeNode *newNode=new TreeNode(v);
            newNode->left=root;
            return newNode;
        }
        insert(root,v,1,d);
        return root;
    }
};