class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int>dp(A.size()+1);
        for(int i=1;i<=A.size();i++)
        {
            int max_elem=-1;
            for(int j=i-1;j>=i-K && j>=0;j--)
            {
                max_elem=max(max_elem,A[j]);
                dp[i]=max(dp[i],dp[j]+max_elem*(i-j));
            }
        }
        return dp[A.size()];
    }
};

// dp[i] = dp[j] + (i-j) * max_elem