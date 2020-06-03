class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > lcs(text1.size()+1, vector<int>(text2.size()+1,0));
        for(int i=0;i<=text1.size();i++)
        {
            for(int j=0;j<=text2.size();j++)
            {
                if(i==0||j==0)
                    lcs[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        return lcs[text1.length()][text2.length()];
    }
};