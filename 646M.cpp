class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int>dp(pairs.size(),1);
        int longest_chain=0;
        for(int i=0;i<pairs.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            longest_chain=max(longest_chain,dp[i]);
        }
        return longest_chain;
    }
};