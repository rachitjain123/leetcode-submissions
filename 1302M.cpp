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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            int sz=q.size();
            sum=0;
            while(sz--)
            {
                TreeNode *tp=q.front();
                q.pop();
                sum+=tp->val;
                if(tp->left!=NULL)
                    q.push(tp->left);
                if(tp->right!=NULL)
                    q.push(tp->right);
            }
            
        }
        return sum;
    }
};