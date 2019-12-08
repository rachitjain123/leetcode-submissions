class Solution {
public:
    bool checkNos(unordered_map<int,int> &mp, vector<int>&v)
    {
        for(int i=0;i<v.size();i++)
        {
            if(mp[v[i]]==0)
                continue;
            if(mp[v[i]*2]>=1)
            {
                mp[v[i]*2]--;
                mp[v[i]]--;
            }
            else
                return false;
        }
        return true;
    }
    bool canReorderDoubled(vector<int>& A) 
    {
        unordered_map<int,int>mp;
        vector<int>v1,v2;
        int num_zeroes=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==0)
            {
                num_zeroes++;
                continue;
            }
            else if(A[i]<0)
                v2.push_back(A[i]);
            else
                v1.push_back(A[i]);
            mp[A[i]]++;
        }
        if(num_zeroes%2)
            return false;
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        if(checkNos(mp,v1) && checkNos(mp,v2))
            return true;
        return false;
    }
};