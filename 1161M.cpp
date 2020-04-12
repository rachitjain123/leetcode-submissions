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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int maxSum=INT_MIN,smallest_level=1,level=0;
        while(!q.empty())
        {
            int sz=q.size();
            int sumPerLevel=0;
            level++;
            while(sz--)
            {
                TreeNode *tmp=q.front();
                q.pop();
                sumPerLevel+=tmp->val;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            if(sumPerLevel>maxSum)
            {
                maxSum=sumPerLevel;
                smallest_level=level;
            }
        }
        return smallest_level;
    }
};