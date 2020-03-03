class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<pair<int,int> >elements;
        int num=0;
        int ans=0;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        for(auto x:mp)
            elements.push_back({x.second,x.first});
        sort(elements.rbegin(),elements.rend());
        for(auto x:elements)
        {
            num+=x.first;
            ans++;
            if(num>=arr.size()/2)
                break;
        }
        return ans;
    }
};