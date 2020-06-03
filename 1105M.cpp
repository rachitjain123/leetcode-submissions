class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int>dp(books.size());
        for(int i=0;i<books.size();i++)
        {
            int width=0,height=0,min_height=INT_MAX;
            for(int j=i;j>=0;j--)
            {
                width+=books[j][0];
                if(width>shelf_width) break;
                height=max(height,books[j][1]);
                int prev_min=0;
                if(j!=0) prev_min=dp[j-1];
                if(min_height>prev_min+height) min_height=prev_min+height;
            }
            dp[i]=min_height;
        }
        return dp[books.size()-1];
    }
};