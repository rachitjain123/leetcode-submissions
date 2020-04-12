class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int> >q;
        int n=grid.size();
        vector<vector<bool> >vis(n,vector<bool>(n,false));
        int path=0;
        int dx[] ={0,1,0,-1,1,-1,-1,1};
        int dy[] ={1,0,-1,0,1,-1,1,-1};
        q.push({0,0});
        vis[0][0]=true;
        if(grid[0][0])
            return -1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> tp=q.front();
                q.pop();
                int x=tp.first;
                int y=tp.second;
                if(x==n-1 && y==n-1)
                    return path+1;
                for(int i=0;i<8;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<=n-1 && ny>=0 && ny<=n-1 && !vis[nx][ny] && !grid[nx][ny])
                    {
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
            path++;
        }
        return -1;
    }
};