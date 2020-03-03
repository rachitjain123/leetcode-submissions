class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++)
        {
            int x=i,y=0,cnt=0;
            vector<int>diag;
            while(x<mat.size() && y<mat[0].size())
            {
                diag.push_back(mat[x][y]);
                x++;y++;
            }
            sort(diag.begin(),diag.end());
            x=i,y=0;
            while(x<mat.size() && y<mat[0].size())
            {
                mat[x][y]=diag[cnt++];
                x++;y++;
            }
        }
        for(int j=1;j<mat[0].size();j++)
        {
            int x=0,y=j,cnt=0;
            vector<int>diag;
            while(x<mat.size() && y<mat[0].size())
            {
                diag.push_back(mat[x][y]);
                x++;y++;
            }
            sort(diag.begin(),diag.end());
            x=0,y=j;
            while(x<mat.size() && y<mat[0].size())
            {
                mat[x][y]=diag[cnt++];
                x++;y++;
            }
        }
        return mat;
    }
};