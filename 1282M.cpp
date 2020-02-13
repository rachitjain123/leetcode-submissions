class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int> >v;
        vector<vector<int> >groups;
        for(int i=0;i<groupSizes.size();i++)
            v.push_back({groupSizes[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            int cnt=1,j=i;
            vector<int>tmp;
            while(cnt<=v[i].first)
            {
                tmp.push_back(v[j].second);
                j++;
                cnt++;
            }
            i=j-1;
            groups.push_back(tmp);
        }
        return groups;
    }
};