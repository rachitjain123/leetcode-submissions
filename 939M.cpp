class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int area=INT_MAX;
        sort(points.begin(),points.end());
        unordered_map<int,unordered_map<int,int> > mp;
        for(int i=0;i<points.size();i++)
            mp[points[i][0]][points[i][1]]=1;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];
                
                int x3=points[j][0];
                int y3=points[j][1];
                
                if(x1==x3||y1==y3)
                    continue;
                
                int x2=x3;
                int y2=y1;
                
                int x4=x1;
                int y4=y3;
                
                if(mp.find(x2)!=mp.end() && mp[x2].find(y2)!=mp[x2].end() && mp.find(x4)!=mp.end() && mp[x4].find(y4)!=mp[x4].end())
                    area=min(area,abs(x1-x3)*abs(y1-y3));
            }
        }
        if(area==INT_MAX)
            return 0;
        return area;
    }
};