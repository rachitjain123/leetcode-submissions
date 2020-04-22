class Solution {
    vector<int>adj[2001];
    bool bipartiteCheck(vector<int> &col, int src)
    {
        queue<int>q;
        q.push(src);
        col[src]=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int p1=q.front();
                q.pop();
                for(int i=0;i<adj[p1].size();i++)
                {
                    if(col[adj[p1][i]]==-1)
                    {
                        q.push(adj[p1][i]);
                        col[adj[p1][i]]=1-col[p1];
                    }
                    else if(col[adj[p1][i]]!=1-col[p1])
                        return false;
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int>col(N+1,-1);
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=N;i++)
        {
            if(col[i]==-1 && !bipartiteCheck(col,i))
                return false;
        }
        return true;
    }
};