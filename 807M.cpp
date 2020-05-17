class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>sk1,sk2;
        int max_increase=0;
        for(int i=0;i<grid.size();i++)
        {
            int max_el=0;
            for(int j=0;j<grid[i].size();j++)
                max_el=max(max_el,grid[i][j]);
            sk1.push_back(max_el);
        }
        for(int j=0;j<grid[0].size();j++)
        {
            int max_el=0;
            for(int i=0;i<grid.size();i++)
                max_el=max(max_el,grid[i][j]);
            sk2.push_back(max_el);
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
                max_increase+=min(sk1[i],sk2[j])-grid[i][j];
        }
        return max_increase;
    }
};