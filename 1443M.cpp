class Solution {
    int getMinMoves(int src, int parent,vector<bool> &hasApple, vector<vector<int> > &adj)
    {
        int moves=0;
        for(int i=0;i<adj[src].size();i++)
        {
            if(adj[src][i]!=parent)
                moves += getMinMoves(adj[src][i],src,hasApple,adj);
        }
        if(moves==0 && !hasApple[src]) return 0;
        return moves+1;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // good way to define like that -> vector<vector<int> > adj(n)
        vector<vector<int> > adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int moves = getMinMoves(0,-1,hasApple,adj);
        if(!moves) return 0;
        return (moves-1)*2;
    }
};