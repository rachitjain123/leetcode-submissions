#include <bits/stdc++.h>
#define  pb push_back
#define nl "\n"
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

void deleteLinks(vector<TreeNode *> &forest, TreeNode *root, set<int> &st)
{
	if(root==NULL)
		return NULL;
	deleteLinks(root->left,st);
	deleteLinks(root->right,st);
	if(root->left!=NULL && st.find(root->left->val)!=st.end())
	{
		forest.push_back(root->left);
		root->left=NULL;
	}
	if(root->right!=NULL && st.find(root->right->val)!=st.end())
	{
		forest.push_back(root->right);
		root->right=NULL;
	}
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
{
	set<int>st;
	for(auto x:to_delete)
		st.insert(x);
	vector<TreeNode *> forest;
	deleteLinks(forest,root,st);
	return forest;
}
int main()
{
	fastScan;
	
}
