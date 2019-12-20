class Solution {
    long double getDistance(pair<long double,long double>p1,pair<long double,long double>p2)
    {
        long double x1=p1.first;
        long double y1=p1.second;
        long double x2=p2.first;
        long double y2=p2.second;
        long double dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        return dist;
    }
public:
     double minAreaFreeRect(vector<vector<int>>& points) { 
        map<pair<pair<long double,long double>,long double>,vector<pair<pair<long double,long double>,pair<long double,long double> > >>mp;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                long double center_x=(long double)((long double)points[i][0]+(long double)points[j][0])/2;
                long double center_y=(long double)((long double)points[i][1]+(long double)points[j][1])/2;
                long double distance=(points[i][1]-points[j][1])*(points[i][1]-points[j][1])+(points[i][0]-points[j][0])*(points[i][0]-points[j][0]);
                mp[{{center_x,center_y},distance}].push_back({{points[i][0],points[i][1]},{points[j][0],points[j][1]}});
            }
        }
        long double min_area=-1;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pair<pair<long double,long double>,long double> p1 =it->first;
            long double c1x=p1.first.first;
            long double c1y=p1.first.second;
            long double dist=p1.second;

            vector<pair<pair<long double,long double>,pair<long double,long double> > >v=it->second;
            if(v.size()<=1)
                continue;
            long double x1=v[0].first.first;
            long double y1=v[0].first.second;
            long double x2=v[0].second.first;
            long double y2=v[0].second.second;
            
            long double x3=v[1].first.first;
            long double y3=v[1].first.second;
            long double x4=v[1].second.first;
            long double y4=v[1].second.second;
            long double l=getDistance({x1,y1},{x3,y3});
            long double b=getDistance({x1,y1},{x4,y4});
            long double area=l*b;
            if(min_area==-1)
                min_area=area;
            else
                min_area=min(min_area,area);
        }
        if(min_area==-1)
            min_area=0;
        return min_area;
    }
};