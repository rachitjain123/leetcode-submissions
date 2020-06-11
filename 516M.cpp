class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > dp(s.length(),vector<int>(s.length()));
        int longestSeq=1;
        for(int i=0;i<s.length();i++)
            dp[i][i]=1;
        for(int len=2;len<=s.length();len++)
        {
            for(int i=0;i<s.length()-len+1;i++)
            {
                int j=i+len-1;
                if(len==2 && s[i]==s[j])
                    dp[i][j]=2;
                else if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                longestSeq=max(longestSeq,dp[i][j]);
            }
        }
        return longestSeq;
    }
};