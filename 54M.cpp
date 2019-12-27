class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int k=0,i=0,j=0,ord=1;
        vector<int>v;
        if(matrix.empty())
            return v;
        int m=matrix.size();
        int n=matrix[0].size();
        while(k<m*n)
        {
            v.push_back(matrix[i][j]);
            matrix[i][j]=0;
            if(ord==1)
            {
                j++;
                if(j==n||matrix[i][j]==0)
                {
                    j--;
                    i++;
                    ord=2;
                }
            }
            else if(ord==2)
            {
                i++;
                if(i==m||matrix[i][j]==0)
                {
                    i--;
                    j--;
                    ord=3;
                }
            }
            else if(ord==3)
            {
                j--;
                if(j<0||matrix[i][j]==0)
                {
                    j++;
                    i--;
                    ord=4;
                }
            }
            else
            {
                i--;
                if(i<0||matrix[i][j]==0)
                {
                    i++;
                    j++;
                    ord=1;
                }
            }
            k++;
        }
        return v;
    }
};