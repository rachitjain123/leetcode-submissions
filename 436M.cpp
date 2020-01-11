class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>stored_vals(intervals.size());
        vector<pair<int,pair<int,int> > >v;
        for(int i=0;i<intervals.size();i++)
            v.push_back({intervals[i][0],{intervals[i][1],i}});
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            int low=i+1,high=v.size()-1,ans=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(v[mid].first>=v[i].second.first)
                {
                    ans=v[mid].second.second;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            stored_vals[v[i].second.second]=ans;
            
        }
        return stored_vals;                         
    }
};