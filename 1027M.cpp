class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int,unordered_map<int,int> > dp;
        int las=2;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=A[i]-A[j];
                if(dp[diff].find(j)==dp[diff].end())
                    dp[diff][i]=2;
                else
                    dp[diff][i]=max(dp[diff][i],dp[diff][j]+1);
                las=max(las,dp[diff][i]);
            }
        }
        return las;
    }
};