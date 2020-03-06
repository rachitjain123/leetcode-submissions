/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    vector<TreeNode *> nodeList;
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode *rt=q.front();
                nodeList.push_back(rt);
                q.pop();
                if(rt->left!=NULL)
                    q.push(rt->left);
                if(rt->right!=NULL)
                    q.push(rt->right);
            }
        }
    }
    int insert(int v) {
        TreeNode *nd=new TreeNode(v);
        nodeList.push_back(nd);
        TreeNode *parent=nodeList[nodeList.size()/2-1];
        if(nodeList.size()%2==0)
            parent->left=nd;
        else
            parent->right=nd;
        return parent->val;
    }
    
    TreeNode* get_root() {
        return nodeList[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */