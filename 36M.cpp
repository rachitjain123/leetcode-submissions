class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // row check
        for(int i=0;i<9;i++)
        {
            unordered_map<int,int>mp;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(mp[board[i][j]])
                        return false;
                    mp[board[i][j]]=1;
                }
            }
        }
        
        // column check
        for(int i=0;i<9;i++)
        {
            unordered_map<int,int>mp;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    if(mp[board[j][i]])
                        return false;
                    mp[board[j][i]]=1;
                }
            }
        }
        
        // sub-boxes check
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                unordered_map<int,int>mp;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(board[k][l]!='.')
                        {
                            if(mp[board[k][l]])
                                return false;
                            mp[board[k][l]]=1;
                        }
                    }        
                }
            }
        }
        return true;
    }
};