/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
    unordered_set<int>st;
    void recoverTree(TreeNode *root, int val)
    {
        if(root==NULL)
            return;
        recoverTree(root->left,val*2+1);
        recoverTree(root->right,val*2+2);
        st.insert(val);
    }
public:
    FindElements(TreeNode* root) {
        recoverTree(root,0);
    }
    
    bool find(int target) {
        if(st.find(target)==st.end())
            return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */