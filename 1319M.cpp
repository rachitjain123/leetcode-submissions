class Solution {
class DSU {
    vector<long>root;
    vector<long>size;
public:
    DSU(int n): root(n),size(n)
    {
        for(int i=0;i<n;i++)
        {
            root[i]=i;
            size[i]=1;
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
    void unite(int n1,int n2)
    {
        int r1=getRoot(n1);
        int r2=getRoot(n2);
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
};
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        DSU dsu_obj(n);
        int num_connected_components=n;
        for(int i=0;i<connections.size();i++)
        {
            int r1=dsu_obj.getRoot(connections[i][0]);
            int r2=dsu_obj.getRoot(connections[i][1]);
            if(r1!=r2)
            {
                dsu_obj.unite(r1,r2);
                num_connected_components--;
            }
        }
        return num_connected_components-1;
    }
};