class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int k=1,i=0,j=0,ord=1;
        vector<vector<int> >v(n,vector<int>(n,0));
        while(k<=n*n)
        {
            v[i][j]=k++;
            if(ord==1)
            {
                j++;
                if(j==n||v[i][j]!=0)
                {
                    j--;
                    i++;
                    ord=2;
                }
            }
            else if(ord==2)
            {
                i++;
                if(i==n||v[i][j]!=0)
                {
                    i--;
                    j--;
                    ord=3;
                }
            }
            else if(ord==3)
            {
                j--;
                if(j<0||v[i][j]!=0)
                {
                    j++;
                    i--;
                    ord=4;
                }
            }
            else
            {
                i--;
                if(i<0||v[i][j]!=0)
                {
                    i++;
                    j++;
                    ord=1;
                }
            }
        }
        return v;
    }
};