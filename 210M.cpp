class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>adj[numCourses];
        vector<int>in_deg(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            pair<int,int>p1={prerequisites[i][0],prerequisites[i][1]};
            adj[p1.second].push_back(p1.first);
            in_deg[p1.first]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(!in_deg[i])
                q.push(i);
        }
        int count=0;
        vector<int>order;
        while(!q.empty())
        {
            int src=q.front();
            q.pop();
            for(int i=0;i<adj[src].size();i++)
            {
                in_deg[adj[src][i]]--;
                if(!in_deg[adj[src][i]])
                    q.push(adj[src][i]);
            }
            order.push_back(src);
            count++;
        }
        if(count!=numCourses)
            order.clear();
        return order;
    }
};