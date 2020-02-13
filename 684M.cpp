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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu_obj(edges.size()+1);
        vector<int>removed_edge;
        for(int i=0;i<edges.size();i++)
        {
            int r1=dsu_obj.getRoot(edges[i][0]);
            int r2=dsu_obj.getRoot(edges[i][1]);
            if(r1!=r2)
                dsu_obj.unite(r1,r2);
            else
            {
                removed_edge.push_back(edges[i][0]);
                removed_edge.push_back(edges[i][1]);
                break;
            }
        }
        return removed_edge;
    }
};