class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int> > overlap_intervals;
        if(intervals.empty())
            return overlap_intervals;
        vector<int>inter;
        inter.push_back(intervals[0][0]);
        inter.push_back(intervals[0][1]);
        overlap_intervals.push_back(inter);
        for(int i=1;i<intervals.size();i++)
        {
            int sz=overlap_intervals.size()-1;
            int l=overlap_intervals[sz][0];
            int r=overlap_intervals[sz][1];
            if(intervals[i][0]>r)
            {
                vector<int>inter;
                inter.push_back(intervals[i][0]);
                inter.push_back(intervals[i][1]);
                overlap_intervals.push_back(inter);
            }
            else if(intervals[i][1]>r)
            {
                overlap_intervals.pop_back();
                vector<int>inter;
                inter.push_back(l);
                inter.push_back(intervals[i][1]);
                overlap_intervals.push_back(inter);
            }
        }
        return overlap_intervals;
    }
};