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
    void getkth(TreeNode *root, int k, vector<int> &smallest_elements)
    {
        if(root==NULL||smallest_elements.size()>=k)
            return;
        getkth(root->left,k,smallest_elements);
        smallest_elements.push_back(root->val);
        getkth(root->right,k,smallest_elements);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>smallest_elements;
        getkth(root,k,smallest_elements);
        return smallest_elements[k-1];
    }
};