class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<pair<int,int> >v;
        for(int i=0;i<A.size();i++)
            v.push_back({A[i],i});
        sort(v.begin(),v.end());
        int maxj=v[A.size()-1].second;
        int width=0;
        for(int i=v.size()-2;i>=0;i--)
        {
            width=max(width,maxj-v[i].second);
            maxj=max(maxj,v[i].second);
        }
        return width;
    }
};