class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n = v.size();
        vector<int>dp(n);
        int sum=0;
        for(int i=2;i<n;i++)
        {
            if(v[i]-v[i-1]==v[i-1]-v[i-2])
                dp[i]=1+dp[i-1];
            sum+=dp[i];
        }
        return sum;
    }
};