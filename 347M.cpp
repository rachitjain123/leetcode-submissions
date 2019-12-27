class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int> > pq;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto x:mp)
            pq.push({x.second,x.first});
        int cnt=1;
        while(!pq.empty() && cnt<=k)
        {
            v.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return v;
    }
};