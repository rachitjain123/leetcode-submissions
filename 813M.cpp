class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<double> pref(A.size()+1);
        vector<double> dp(A.size()+1);
        K--;
        for(int i=0;i<A.size();i++)
            pref[i+1]=pref[i]+A[i];
        for(int i=0;i<A.size();i++)
            dp[i]=(pref[A.size()]-pref[i])/(A.size()-i);
        while(K--)
        {
            for(int i=0;i<A.size();i++)
            {
                for(int j=i+1;j<A.size();j++)
                    dp[i]=max(dp[i],(pref[j]-pref[i])/(j-i)+dp[j]);
            }
        }
        return dp[0];
    }
};