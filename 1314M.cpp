class Solution {
    void prefixSum(vector<vector<int>>& mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=1;j<mat[0].size();j++)
                mat[i][j]+=mat[i][j-1];
        }
        for(int j=0;j<mat[0].size();j++)
        {
            for(int i=1;i<mat.size();i++)
                mat[i][j]+=mat[i-1][j];
        }
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int> > res(mat.size(),vector<int>(mat[0].size(),0));
        prefixSum(mat);
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[0].size();j++)
            {
                int row1=max(i-k,0);
                int col1=max(j-k,0);
                
                int row2=min(i+k,(int)res.size()-1);
                int col2=min(j+k,(int)res[0].size()-1);

                res[i][j] = mat[row2][col2];
                if(row1>0)
                    res[i][j] -= mat[row1-1][col2];
                if(col1>0)
                    res[i][j] -=  mat[row2][col1-1];
                if(row1>0 && col1>0)
                    res[i][j] += mat[row1-1][col1-1];
            }
        }
        
        return res;
    }
};