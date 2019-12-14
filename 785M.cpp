class Solution {
    bool bfs(vector<int> &color,vector<vector<int>>& adj,int src)
    {
        queue<int>q;
        q.push(src);
        int col=1;
        color[src]=col;
        while(!q.empty())
        {
            int sz=q.size();
            col=col*-1;
            while(sz--)
            {
                int tmp=q.front();
                q.pop();
                for(int i=0;i<adj[tmp].size();i++)
                {
                    if(color[adj[tmp][i]]==0)
                    {
                        q.push(adj[tmp][i]);
                        color[adj[tmp][i]]=col;
                    }
                    else if(color[adj[tmp][i]]==color[tmp])
                        return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int>color(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==0)
            {
                if(!bfs(color,graph,i))
                    return false;
            }
        }
        return true;
    }
};