class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int> >v;
        for(int i=0;i<intervals.size();i++)
            v.push_back(make_pair(intervals[i][0],intervals[i][1]));
        sort(v.begin(),v.end());
        int maxi=v[0].second;
        int num=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].second<=maxi)
                num++;
            maxi=max(maxi,v[i].second);
        }
        return v.size()-num;
    }
};