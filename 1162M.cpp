class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> > vis(100,vector<int>(100,0));
        queue<pair<int,int> >q;
        bool is_water=false;
        bool is_land=false;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j])
                {
                    is_land=true;
                    q.push({i,j});
                    vis[i][j]=1;
                }
                else
                    is_water=true;
            }
        }
        if(!is_water||!is_land)
            return -1;
        int level=-1,dist=0;
        while(!q.empty())
        {
            int sz=q.size();
            level++;
            for(int i=0;i<sz;i++)
            {
                pair<int,int> p1=q.front();
                int x=p1.first;
                int y=p1.second;
                if(grid[x][y]==0)
                    dist=max(dist,level);
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx<0||ny<0||nx>=m||ny>=n||vis[nx][ny]||grid[nx][ny]==1)
                        continue;
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return dist;
    }
};