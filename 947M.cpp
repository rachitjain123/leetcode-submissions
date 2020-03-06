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
    int removeStones(vector<vector<int>>& stones) {
        vector<int>col[10001];
        vector<int>row[10001];
        vector<int>row_coord;
        vector<int>col_coord;
        unordered_map<int,int>mp;
        int max_val=0;
        set<int>st;
        DSU dsu_obj(stones.size());
        for(int i=0;i<stones.size();i++)
        {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
            row_coord.push_back(stones[i][0]);
            col_coord.push_back(stones[i][1]);
        }
        for(int l=0;l<row_coord.size();l++)
        {
            int i=row_coord[l];
            if(row[i].empty())
                continue;
            int i1=row[i][0];
            int r1=dsu_obj.getRoot(i1);
            for(int j=1;j<row[i].size();j++)
            {
                int i2=row[i][j];
                int r2=dsu_obj.getRoot(i2);
                if(r1!=r2)
                    dsu_obj.unite(i1,i2);
            }
        }
        for(int l=0;l<col_coord.size();l++) 
        {
            int i=col_coord[l];
            if(col[i].empty())
                continue;
            int i1=col[i][0];
            int r1=dsu_obj.getRoot(i1);
            for(int j=1;j<col[i].size();j++)
            {
                int i2=col[i][j];
                int r2=dsu_obj.getRoot(i2);
                if(r1!=r2)
                    dsu_obj.unite(i1,i2);
            }
        }
        for(int i=0;i<stones.size();i++)
        {
            int r=dsu_obj.getRoot(i);
            mp[r]++;
        }
        for(auto x:mp)
            max_val+=x.second-1;
        return max_val;
    }
};