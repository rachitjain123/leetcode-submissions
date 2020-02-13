class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int score=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i][0]==0)
            {
                for(int j=0;j<A[i].size();j++)
                    A[i][j]=1-A[i][j];
            }
        }
        for(int j=0;j<A[0].size();j++)
        {
            int cnt=0;
            for(int i=0;i<A.size();i++)
            {
                if(A[i][j])
                    cnt++;
            }
            if(A.size()-cnt>cnt)
            {
                for(int i=0;i<A.size();i++)
                    A[i][j]=1-A[i][j];
            }
        }
        for(int i=0;i<A.size();i++)
        {
            int row_val=0;
            for(int j=0;j<A[i].size();j++)
                row_val=row_val*2+A[i][j];
            score+=row_val;
        }
        return score;
    }
};