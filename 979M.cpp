/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int num_moves;
    int extraCoins(TreeNode* root) {
        if(root==NULL) return 0;
        int extraLeftSubTree = extraCoins(root->left);
        int extraRightSubTree = extraCoins(root->right);
        num_moves+=abs(extraLeftSubTree) + abs(extraRightSubTree);
        return extraLeftSubTree + extraRightSubTree + root->val - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        extraCoins(root);
        return num_moves;
    }
};