class Solution {
    void getComp(vector<vector<int>>& A,vector<pair<int,int> > &comp1,int x,int y)
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int m=A.size();
        int n=A[0].size();
        queue<pair<int,int> >q;
        vector<vector<bool> >vis(m,vector<bool>(n,false));
        vis[x][y]=true;
        q.push({x,y});
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int tpx=q.front().first;
                int tpy=q.front().second;
                comp1.push_back({tpx,tpy});
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int newx=tpx+dx[i];
                    int newy=tpy+dy[i];
                    if(newx>=0 && newx<m && newy>=0 && newy<n && !vis[newx][newy] && A[newx][newy])
                    {
                        q.push({newx,newy});
                        vis[newx][newy]=true;
                    }
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        vector<pair<int,int> >comp1;
        int m=A.size();
        int n=A[0].size();
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)
            {
                if(A[i][j])
                {
                    getComp(A,comp1,i,j);
                    break;
                }
            }
            if(!comp1.empty())
                break;
        }
        queue<pair<int,int> >q;
        vector<vector<bool> >vis(m,vector<bool>(n,false));
        for(int i=0;i<comp1.size();i++)
        {
            q.push({comp1[i].first,comp1[i].second});
            vis[comp1[i].first][comp1[i].second]=true;
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int number_flip=0;
        bool gotOtherIsland=false;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int tpx=q.front().first;
                int tpy=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int newx=tpx+dx[i];
                    int newy=tpy+dy[i];
                    if(newx>=0 && newx<m && newy>=0 && newy<n && !vis[newx][newy])
                    {
                        if(A[newx][newy]==1)
                        {
                            gotOtherIsland=true;
                            break;
                        }
                        q.push({newx,newy});
                        vis[newx][newy]=true;
                    }
                }
            }
            if(gotOtherIsland)
                break;
            number_flip++;
        }
        return number_flip;
    }
};