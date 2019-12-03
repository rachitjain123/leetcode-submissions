class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>res;
        set<int>hash[120];
        for(int i=0;i<temp.size();i++)
            hash[temp[i]].insert(i+1);
        for(int i=0;i<temp.size();i++)
        {
            int ans=300100;
            for(int j=temp[i]+1;j<=100;j++)
            {
                if(!hash[j].empty())
                {
                    int day_after=*hash[j].begin();
                    ans=min(ans,day_after);
                }

            }
            if(ans == 300100)
            {
                ans = 0;
                res.push_back(0);

            }
            else
                res.push_back(ans-(i+1));
            hash[temp[i]].erase(i+1);
        }
        return res;
    }
};