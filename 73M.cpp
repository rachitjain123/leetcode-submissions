class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool is_first_row=0;
        bool is_first_column=0;
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[0][j]==0)
                is_first_row=1;
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
                is_first_column=1;
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            if(is_first_row)
                matrix[0][j]=0;
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(is_first_column)
                matrix[i][0]=0;
        }
        return;
    }
};