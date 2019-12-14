class Solution {
    
    bool hasCycle(vector<int> &safe_nodes,vector<vector<int>> &adj,vector<int> &color,int src)
    {
        color[src]=1;
        for(int i=0;i<adj[src].size();i++)
        {
            if(color[adj[src][i]]==1)
                return true;
            if(color[adj[src][i]]==0)
            {
                if(hasCycle(safe_nodes,adj,color,adj[src][i]))
                    return true;
            }
        }
        color[src]=2;
        safe_nodes.push_back(src);
        return false;
    }
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int>color(graph.size());
        vector<int>safe_nodes;
        for(int i=0;i<graph.size();i++)
        {
            if(!color[i])
                hasCycle(safe_nodes,graph,color,i);
        }
        sort(safe_nodes.begin(),safe_nodes.end());
        return safe_nodes;
    }
};