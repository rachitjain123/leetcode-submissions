class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
//         vector<vector<int> > dp(piles.size(),vector<int>(piles.size(),0));
//         int sumCoins=0;
//         for(int i=0;i<piles.size();i++) sumCoins+=piles[i];
//         for(int l=1;l<=piles.size();l++)
//         {
//             for(int i=0;i<piles.size()-l+1;i++)
//             {
//                 int j=i+l-1;
//                 int w=0,x=0,y=0;
//                 if(i+1<=j-1) w = dp[i+1][j-1];
//                 if(i+2<=j) x = dp[i+2][j];
//                 if(i<=j-2) y = dp[i][j-2];
                
//                 dp[i][j]=max(piles[i]+min(w, x), piles[j]+min(w, y));
//             }
//         }
//         if(dp[0][piles.size()-1]>sumCoins-dp[0][piles.size()-1])
//             return true;
//         return false;
    }
};