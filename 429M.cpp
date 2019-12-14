/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *>q;
        q.push(root);
        vector<vector<int> >level_order;
        if(root==NULL)
            return level_order;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>level;
            while(sz--)
            {
                Node *tmp=q.front();
                level.push_back(tmp->val);
                q.pop();
                vector<Node *>children=tmp->children;
                for(int i=0;i<children.size();i++)
                    q.push(children[i]);
            }
            level_order.push_back(level);
        }
        return level_order;
    }
};