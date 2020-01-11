class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int> >lcs(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 ||j==0)
                    lcs[i][j]=0;
                else if(word1[i-1]==word2[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else
                    lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
        return m+n-2*lcs[m][n];
    }
};