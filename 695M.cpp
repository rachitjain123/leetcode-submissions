class Solution {
    int bfs(vector<vector<int>>& grid,vector<vector<bool> >&vis,int x,int y)
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int m=grid.size();
        int n=grid[0].size();
        int island_area=0;
        vis[x][y]=true;
        queue<pair<int,int> >q;
        q.push({x,y});
        while(!q.empty())
        {
            int x1=q.front().first;
            int y1=q.front().second;
            q.pop();
            island_area++;
            for(int i=0;i<4;i++)
            {
                int tmpx=x1+dx[i];
                int tmpy=y1+dy[i];
                if(tmpx<0||tmpx>=m||tmpy<0||tmpy>=n||vis[tmpx][tmpy]||!grid[tmpx][tmpy])
                    continue;
                q.push({tmpx,tmpy});
                vis[tmpx][tmpy]=true;
            }
        }
        return island_area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int max_area=0;
        vector<vector<bool> >vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j])
                    max_area=max(max_area,bfs(grid,vis,i,j));
            }
        }
        return max_area;
    }
};