class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>degree(n);
        vector<int>adj[n];
        vector<int>res;
        queue<int>q;
        if(edges.empty())
        {
            res.push_back(0);
            return res;
        }
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
                degree[i]=0;
            }
        }
        while(n>2)
        {
            int sz=q.size();
            while(sz--)
            {
                int tmp=q.front();
                n--;
                q.pop();
                for(int i=0;i<adj[tmp].size();i++)
                {
                    if(--degree[adj[tmp][i]]==1)
                        q.push(adj[tmp][i]);
                }
            }
        }
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};