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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int levelCount=1;
        while(!q.empty())
        {
            int sz=q.size();
            int nodes=0;
            bool isSeen=true;
            while(sz--)
            {
                TreeNode *tmp=q.front();
                q.pop();
                nodes++;
                if(tmp->left!=NULL)
                {
                    if(!isSeen)
                        return false;
                    q.push(tmp->left);
                }
                else
                    isSeen=false;
                if(tmp->right!=NULL)
                {
                    if(!isSeen)
                        return false;
                    q.push(tmp->right);
                }
                else
                    isSeen=false;
            }
            if(!q.empty() && levelCount!=nodes)
                return false;
            levelCount=levelCount*2;                
        }
        return true;
    }
};