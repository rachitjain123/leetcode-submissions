class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int>mp;
        priority_queue<pair<int,int> >pq;
        vector<int>v;
        for(int i=0;i<barcodes.size();i++)
            mp[barcodes[i]]++;
        for(auto x:mp)
            pq.push({x.second,x.first});
        while(!pq.empty())
        {
            int val1=pq.top().second;
            int freq1=pq.top().first;
            int val2=0,freq2=0;
            pq.pop();
            if(!pq.empty())
            {
                val2=pq.top().second;
                freq2=pq.top().first;
                pq.pop();
            }
            if(val2!=0)
            {
                v.push_back(val1);
                v.push_back(val2);
            }
            else
                v.push_back(val1);
            if(freq1>1)
                pq.push({freq1-1,val1});
            if(freq2>1)
                pq.push({freq2-1,val2});
        }
        return v;
    }
};