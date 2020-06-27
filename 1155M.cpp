class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        long long int mod = (long long int)(1e9+7);
        vector<vector<long long int> > dp(d+1,vector<long long int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=d;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int k=1;k<=f;k++)
                {
                    if(j>=k)
                        dp[i][j]=(dp[i][j]%mod+dp[i-1][j-k]%mod)%mod;
                }
            }
        }
        return dp[d][target];
    }
};