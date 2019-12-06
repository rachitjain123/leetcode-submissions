class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int num_squares=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i==0||j==0)
                {
                    if(matrix[i][j]==1)
                        num_squares++;
                }
                else if(matrix[i][j]==1)
                {
                    matrix[i][j]=min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1]))+1;
                    num_squares+=matrix[i][j];
                }
            }
        }
        return num_squares;
    }
};