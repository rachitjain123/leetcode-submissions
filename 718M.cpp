class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int na = a.size(), nb= b.size();
        int dp[na+1][nb+1] = {};
        int mx = 0;
        for (int i = 1; i <= na; ++i) for (int j = 1; j <=nb; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            mx = max(mx,dp[i][j]);
        }
        
        return mx;
    }
};