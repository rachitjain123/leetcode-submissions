class Solution {
    int backtrackGoldPath(int x, int y, vector<vector<int> > &grid,int goldSum)
    {
        int dx[] ={0,0,1,-1};
        int dy[] ={-1,1,0,0};
        int m=grid.size(),n=grid[0].size();
        goldSum+=grid[x][y];
        int maxGoldSum=goldSum;
        int curCellVal = grid[x][y];
        grid[x][y]=-1;
        for(int i=0;i<4;i++)
        {
            int xnew=x+dx[i];
            int ynew=y+dy[i];
            if(xnew>=0 && xnew<m && ynew>=0 && ynew<n && grid[xnew][ynew]>0)
                maxGoldSum = max(maxGoldSum,backtrackGoldPath(xnew,ynew,grid,goldSum));
        }
        grid[x][y]=curCellVal;
        return maxGoldSum;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int maxGoldSum = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    maxGoldSum=max(maxGoldSum,backtrackGoldPath(i,j,grid,0));
            }
        }
        return maxGoldSum;
    }
};