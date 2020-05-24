class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int> >dp(A.size(),vector<int>(A.size(),0));
        int min_pathSum=INT_MAX;
        for(int i=0;i<A.size();i++)
            dp[0][i]=A[0][i];
        for(int i=1;i<A.size();i++)
        {
            for(int j=0;j<A.size();j++)
            {
                if(j==0)
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+A[i][j];
                else if(j==A.size()-1)
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+A[i][j];
                else
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j+1],dp[i-1][j-1]))+A[i][j];
            }
        }
        for(int j=0;j<A.size();j++)
            min_pathSum = min(min_pathSum, dp[A.size()-1][j]);
        return min_pathSum;
    }
};