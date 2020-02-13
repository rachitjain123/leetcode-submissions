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
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu_obj(27);
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
                dsu_obj.unite(equations[i][0]-'a', equations[i][3]-'a');
        }
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]!='=')
            {
                int r1=dsu_obj.getRoot(equations[i][0]-'a');
                int r2=dsu_obj.getRoot(equations[i][3]-'a');
                if(r1==r2)
                    return false;
            }
        }
        return true;
    }
};