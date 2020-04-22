class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> bfsQ;
        
        if (!root) {
            return root;
        }
        
        bfsQ.push(root);
        
        while (!bfsQ.empty()) {
            int cnt = bfsQ.size();

            while (cnt--) {
                Node* tmpNode = bfsQ.front();
                bfsQ.pop();

                if (cnt > 0) {
                    tmpNode->next = bfsQ.front();
                }
                
                if (tmpNode->left) {
                    bfsQ.push(tmpNode->left);
                }

                if (tmpNode->right) {
                    bfsQ.push(tmpNode->right);
                }
            }
        }
        
        return root;
    }
};