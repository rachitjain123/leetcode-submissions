class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        vector<pair<int,int> >adj[N+1];
        vector<bool>vis(N+1,false);
        vector<int>dist(N+1,INT_MAX);
        set<pair<int,int> >st;
        int total_time=0;
        for(int i=0;i<times.size();i++)
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        dist[k]=0;
        st.insert({dist[k],k});
        while(!st.empty())
        {
            auto it=st.begin();
            int u=it->second;
            st.erase(it);
            if(!vis[u])
            {
                for(int i=0;i<adj[u].size();i++)
                {
                    int v=adj[u][i].first;
                    int wt=adj[u][i].second;
                    if(dist[v]>dist[u]+wt)
                    {
                        dist[v]=dist[u]+wt;
                        st.insert({dist[v],v});
                    }
                }
            }
            vis[u]=true;
        }
        for(int i=1;i<=N;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            total_time=max(total_time,dist[i]);
        }
        return total_time;
    }
};