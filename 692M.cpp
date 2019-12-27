class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        set<pair<int,string> > pq;
        vector<string>v;
        for(int i=0;i<words.size();i++)
            mp[words[i]]++;
        for(auto x:mp)
            pq.insert({-x.second,x.first});
        int cnt=1;
        while(!pq.empty() && cnt<=k)
        {
            v.push_back((*pq.begin()).second);
            pq.erase(pq.begin());
            cnt++;
        }
        return v;
    }
};