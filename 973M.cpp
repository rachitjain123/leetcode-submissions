class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        set<pair<int,pair<int,int> > >st;
        for(int i=0;i<points.size();i++)
        {
            st.insert({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
        }
        vector<vector<int> >ans;
        for(auto x:st)
        {
            if(K==0)
                break;
            vector<int>pair;
            pair.push_back(x.second.first);
            pair.push_back(x.second.second);
            ans.push_back(pair);
            K--;
        }
        return ans;
    }
};