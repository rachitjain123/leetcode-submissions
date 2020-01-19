class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time_list;
        int min_diff=INT_MAX;
        for(int i=0;i<timePoints.size();i++)
        {
            int hours=(timePoints[i][0]-'0')*10+(timePoints[i][1]-'0');
            int minutes=(timePoints[i][3]-'0')*10+(timePoints[i][4]-'0');
            int time=hours*60+minutes;
            time_list.push_back(time);
        }
        sort(time_list.begin(),time_list.end());
        for(int i=0;i<time_list.size();i++)
        {
            if(i==0)
                min_diff=min(min_diff,abs(time_list[0]-time_list[time_list.size()-1]));
            else
                min_diff=min(min_diff,time_list[i]-time_list[i-1]);
            min_diff=min(min_diff,1440-min_diff);
        }
        return min_diff;
    }
};