class Solution {
public:
    int vis[101][101];
    vector<pair<int,int> >conn_comp;
    void dfs(int x,int y,int m,int n,vector<vector<int>>& grid)
    {
        vis[x][y]=1;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        conn_comp.push_back({x,y});
        for(int i=0;i<4;i++)
        {
		    int tmpx=x+dx[i];
		    int tmpy=y+dy[i];
		    if(tmpx<0||tmpx>=m||tmpy<0||tmpy>=n||vis[tmpx][tmpy]||grid[tmpx][tmpy])
                continue;
		    dfs(tmpx,tmpy,m,n,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==0)
                {
                    dfs(i,j,m,n,grid);
                    int np=1;
                    for(auto x:conn_comp)
                    {
                        if(x.first==0||x.first==m-1||x.second==0||x.second==n-1)
                        {
                            np=0;
                            break;
                        }
                    }
                    ans+=np;
                    conn_comp.clear();
                }

            }
	    }
        return ans;
    }
};