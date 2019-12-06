class Solution {
    int size[201];
    int root[201];
public:
    void init(int n)
    {
        for(int i=0;i<=n;i++)
        {
            size[i]=1;
            root[i]=i;
        }
    }
    int getRoot(int node)
    {
        while(root[node]!=node)
        {
            root[node]=root[root[node]];
            node=root[node];
        }
        return node;
    }
    void unite(int a,int b)
    {
        int r1=getRoot(a);
        int r2=getRoot(b);
        if(size[r1]<size[r2])
        {
            root[r1]=root[r2];
            size[r2]+=size[r1];
        }
        else
        {
            root[r2]=root[r1];
            size[r1]+=size[r2];
        }
    }

    int findCircleNum(vector<vector<int>>& M) 
    {
        init(M.size());
        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M[i].size();j++)
            {
                if(M[i][j]==1 && getRoot(i+1)!=getRoot(j+1))
                    unite(i+1,j+1);
            }
        }
        set<int>friend_circles;
        for(int i=0;i<M.size();i++)
            friend_circles.insert(getRoot(i+1));
        return friend_circles.size();
    }
};