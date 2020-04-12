class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        queue<pair<int,int> >q;
        q.push({headID,0});
        int num_minutes=0;
        while(!q.empty())
        {
            int sz=q.size();
            int max_time=0;
            while(sz--)
            {
                int empl=q.front().first;
                int curTime=q.front().second;
                num_minutes=max(num_minutes,q.front().second);
                q.pop();
                for(int i=0;i<adj[empl].size();i++)
                    q.push({adj[empl][i],curTime+informTime[empl]});
            }
        }
        return num_minutes;
    }
};