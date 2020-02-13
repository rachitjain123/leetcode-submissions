class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int,priority_queue<int> > mp;
        priority_queue<int>pq;
        int sum=0;
        for(int i=0;i<labels.size();i++)
            mp[labels[i]].push(values[i]);
        for(auto x:mp)
        {
            int cnt=1;
            while(!x.second.empty() && cnt<=use_limit)
            {
                pq.push(x.second.top());
                x.second.pop();
                cnt++;
            }
        }
        while(!pq.empty() && num_wanted)
        {
            sum+=pq.top();
            pq.pop();
            num_wanted--;
        }
        return sum;
    }
};