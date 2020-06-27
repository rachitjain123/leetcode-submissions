class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(60);
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        dp[4]=4;
        for(int i=5;i<=n;i++)
            dp[i]=max(dp[i-3],i-3)*3;
        return dp[n];
    }
};