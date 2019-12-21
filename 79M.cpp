class Solution {
public:
    bool word_search(vector<vector<bool> > &vis,int x,int y,vector<vector<char>>& board, string wd, string target)
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int m=board.size();
        int n=board[0].size();
        if(wd.length()==target.length() && wd[wd.length()-1]==target[wd.length()-1])
            return true;
        if(wd.length()>target.length())
            return true;
        if(wd[wd.length()-1]!=target[wd.length()-1])
            return false;
        for(int i=0;i<4;i++)
        {
            int tmpx=x+dx[i];
            int tmpy=y+dy[i];
            if(tmpx<0||tmpy<0||tmpx>=m||tmpy>=n||vis[tmpx][tmpy])
                continue;
            wd+=board[tmpx][tmpy];
            vis[tmpx][tmpy]=true;
            if(word_search(vis,tmpx,tmpy,board,wd,target))
                return true;
            wd.pop_back();
            vis[tmpx][tmpy]=false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string target) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!=target[0])
                    continue;
                string wd;
                wd.push_back(board[i][j]);
                vector<vector<bool> >vis(m,vector<bool>(n,false));
                vis[i][j]=true;
                if(word_search(vis,i,j,board,wd,target))
                    return true;
            }
        }
        return false;
    }
};

// Efficient solution
class Solution {
    bool backtrack(vector<vector<char>>& board,string target,int i,int j, int pos)
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int m=board.size();
        int n=board[0].size();
        if(pos>=target.length())
            return true;
        if(i<0||j<0||i>=m||j>=n)
            return false;
        char tmp=board[i][j];
        if(board[i][j]=='!'|| board[i][j]!=target[pos])
            return false;
        board[i][j]='!';
        for(int k=0;k<4;k++)
        {
            int tmpx=i+dx[k];
            int tmpy=j+dy[k];
            if(backtrack(board,target,tmpx,tmpy,pos+1))
                return true;
        }
        board[i][j]=tmp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string target) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!=target[0])
                    continue;
                if(backtrack(board,target,i,j,0))
                    return true;
            }
        }
        return false;
    }
};