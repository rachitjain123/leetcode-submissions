class Solution {
    static int cmp(vector<int> i1, vector<int> i2)
    {
        if(i1[1]!=i2[1])
            return i1[1]<i2[1];
        return i1[0]<i2[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);   
        int tmp=INT_MIN;
        int cnt=0;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]<tmp)
                cnt++;
            else
                tmp=max(tmp,intervals[i][1]);
        }
        return cnt;
    }
};