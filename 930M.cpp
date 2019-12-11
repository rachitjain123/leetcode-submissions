class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) 
    {
        int pref[30001];
        int sum=0,num_subarrays=0,cnt_seroes=0;
        memset(pref,0,sizeof(pref));
        for(int i=0;i<A.size();i++)
        {
            sum+=A[i];
            if(sum>=S)
                num_subarrays+=pref[sum-S];
            if(sum==S)
                num_subarrays=num_subarrays+1;
            pref[sum]++;
        }
        return num_subarrays;
    }
};