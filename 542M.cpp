class Solution {
public:
    // BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        queue<pair< pair<int,int>,int > >q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!matrix[i][j])
                    q.push({{i,j},0});
                else
                	matrix[i][j]=-1;
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int level=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=m||nx<0||ny>=n||ny<0||matrix[nx][ny]!=-1)
                    continue;
                q.push({{nx,ny},level+1});
                matrix[nx][ny]=level+1;
            }
        }
        return matrix;
    }
    // DP
    //dp[i][j]=min(dp[i][j-1],dp[i-1][j])+1 -> 1st pass
    //dp[i][j]=min(dp[i][j+1],dp[i+1][j])+1 -> 2nd pass
    //return dp
};