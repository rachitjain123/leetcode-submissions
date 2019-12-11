class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
    	map<int,int>mp;
    	int num_not_crossed=-1;
    	for(int i=0;i<wall.size();i++)
    	{
    		int width=0;
    		for(int j=0;j<wall[i].size()-1;j++)
    		{
    			width+=wall[i][j];
    			mp[width]++;
    		}
    	}
    	if(mp.empty())
    		num_not_crossed=0;
    	else
    	{
    		for(auto x:mp)
    			num_not_crossed=max(num_not_crossed,x.second);
    	}
    	return wall.size()-num_not_crossed;
    }
};