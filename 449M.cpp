/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode *constructBSTfromPreOrder(vector<int> &preorder,int min_val, int max_val,int *index)
    {
        if((*index)>=preorder.size()||preorder[*index]<min_val||preorder[*index]>max_val)
            return NULL;
        TreeNode *root=new TreeNode(preorder[(*index)++]);
        root->left=constructBSTfromPreOrder(preorder,min_val,root->val,index);
        root->right=constructBSTfromPreOrder(preorder,root->val,max_val,index);
        return root;
        
    }
    void getPreOrder(TreeNode *root,vector<int> &preorder_traversal)
    {
        if(root==NULL)
            return;
        preorder_traversal.push_back(root->val);
        getPreOrder(root->left,preorder_traversal);
        getPreOrder(root->right,preorder_traversal);
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> preorder_traversal;
        string sep=",";
        string serialize_str;
        getPreOrder(root,preorder_traversal);
        for(int i=0;i<preorder_traversal.size();i++)
        {
            serialize_str+=to_string(preorder_traversal[i]);
            if(i!=preorder_traversal.size()-1)
                serialize_str+=sep;
        }
        return serialize_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder_traversal;
        for(int i=0;i<data.size();i++)
        {
            int element=0,j=i;
            while(j<data.size() && data[j]!=',')
            {
                element=element*10+data[j]-'0';
                j++;
            }
            preorder_traversal.push_back(element);
            i=j;
        }
        int index=0;
        return constructBSTfromPreOrder(preorder_traversal,INT_MIN,INT_MAX, &index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));