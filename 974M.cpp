class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        vector<int>mp(k);
        int sum=0;
        int ans=0;
        for(int i=0;i<A.size();i++)
        {
            sum=(sum%k+A[i]%k+k)%k;
            if(sum%k==0)
                ans++;
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};