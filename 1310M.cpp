class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pref(arr.size());
        vector<int>res;
        int num=0;
        for(int i=0;i<arr.size();i++)
        {
            num=(int)num^arr[i];
            pref[i]=num;
        }
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0)
                res.push_back(pref[r]);
            else
                res.push_back((int)pref[r]^pref[l-1]);
        }
        return res;
    }
};