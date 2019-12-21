class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int> >lcs(A.size()+1,vector<int>(B.size()+1,0));
        for(int i=0;i<=A.size();i++)
        {
            for(int j=0;j<=B.size();j++)
            {
                if(i==0||j==0)
                    lcs[i][j]=0;
                else if(A[i-1]==B[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else
                    lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
        return lcs[A.size()][B.size()];
    }
};