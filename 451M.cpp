class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        vector<pair<int,char>>v;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            char ch=it->first;
            int frequency=it->second;
            v.push_back({frequency,ch});
        }
        sort(v.rbegin(),v.rend());
        string res;
        for(int i=0;i<v.size();i++)
        {
            int frequency=v[i].first;
            while(frequency)
            {
                res.push_back(v[i].second);
                frequency--;
            }
        }
        return res;
    }
};