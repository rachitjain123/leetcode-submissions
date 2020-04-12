class Solution {
    void getItenary(vector<string> &itenary, unordered_map<string, priority_queue<string, vector<string>, greater<string> > > &adj, string src)
    {
        while(!adj[src].empty())
        {
            string dest=adj[src].top();
            adj[src].pop();
            getItenary(itenary,adj,dest);
        }
        itenary.push_back(src);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string> > > adj;
        vector<string>itenary;
        for(int i=0;i<tickets.size();i++)
            adj[tickets[i][0]].push(tickets[i][1]);
        getItenary(itenary,adj,"JFK");
        reverse(itenary.begin(),itenary.end());
        return itenary;
    }
};