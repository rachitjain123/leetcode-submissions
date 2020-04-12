class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end());
        int r=points[0][1],min_arrows=1;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=r)
                r=min(points[i][1],r);
            else
            {
                r=points[i][1];
                min_arrows++;
            }
        }
        return min_arrows;
    }
};