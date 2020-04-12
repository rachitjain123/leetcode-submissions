class Solution {
    int getNumNode(int root,vector<int> &leftChild, vector<int> &rightChild)
    {
        if(root==-1)
            return 0;
        int ltree=getNumNode(leftChild[root],leftChild,rightChild);
        int rtree=getNumNode(rightChild[root],leftChild,rightChild);
        return ltree+rtree+1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root=-1,edges=0;
        vector<int>degree(n);
        for(int i=0;i<leftChild.size();i++)
        {
            if(leftChild[i]!=-1) 
            { 
                edges++; 
                degree[leftChild[i]]++;
            }
            if(rightChild[i]!=-1) 
            {
                edges++;
                degree[rightChild[i]]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(degree[i]==0) root=i;
            else if(degree[i]>1) return false;
        }
        if(edges!=n-1 || root==-1) return false;
        if(getNumNode(root,leftChild,rightChild)!=n) return false;
        return true;
    }
};