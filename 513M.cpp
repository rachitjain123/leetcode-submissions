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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        TreeNode *firstNode;
        int val_first_node;
        while(!q.empty())
        {
            int sz=q.size();
            firstNode=NULL;
            for(int i=0;i<sz;i++)
            {
                TreeNode *tmp=q.front();
                if(firstNode==NULL)
                {
                    firstNode=tmp;
                    val_first_node=tmp->val;
                }
                q.pop();
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
            }
        }
        return val_first_node;
    }
};