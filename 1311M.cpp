class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int>q;
        vector<bool>vis(friends.size());
        unordered_map<string,int>videos_freq;
        vector<pair<int,string> >ans;
        vector<string>fans;
        vis[id]=true;
        q.push(id);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int src=q.front();
                q.pop();
                for(int i=0;i<friends[src].size();i++)
                {
                    if(!vis[friends[src][i]])
                    {
                        vis[friends[src][i]]=true;
                        q.push(friends[src][i]);
                        if(level==1)
                        {
                            for(int j=0;j<watchedVideos[friends[src][i]].size();j++)
                            {
                                string vid=watchedVideos[friends[src][i]][j];
                                videos_freq[vid]++;
                            }

                        }
                    }
                }
            }
            level--;
        }
        for(auto x:videos_freq)
            ans.push_back({x.second,x.first});
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            fans.push_back(ans[i].second);
        return fans;
    }
};