class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<bool>is_present_row(grid.size());
        vector<bool>is_present_column(grid[0].size());
        int servers_comm=0;
        for(int i=0;i<grid.size();i++)
        {
            int sum=0;
            for(int j=0;j<grid[i].size();j++)
                sum+=grid[i][j];
            if(sum>=2)
                is_present_row[i]=true;
            else
                is_present_row[i]=false;
        }
        for(int j=0;j<grid[0].size();j++)
        {
            int sum=0;
            for(int i=0;i<grid.size();i++)
                sum+=grid[i][j];
            if(sum>=2)
                is_present_column[j]=true;
            else
                is_present_column[j]=false;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if((is_present_row[i]||is_present_column[j]) && grid[i][j]==1)
                    servers_comm++;
            }
        }
        return servers_comm;
    }
};