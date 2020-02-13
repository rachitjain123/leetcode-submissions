class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>mp(1001);
        int num_people=0;
        for(int i=0;i<trips.size();i++)
        {
            mp[trips[i][1]]+=trips[i][0];
            mp[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<=1000;i++)
        {
            num_people+=mp[i];
            if(num_people>capacity)
                return false;
        }
        return true;
    }
};