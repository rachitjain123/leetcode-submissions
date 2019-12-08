class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	int len=nums.size();
        int vis[len];
        memset(vis,0,sizeof(vis));
        int longest_length=1;
        for(int i=0;i<len;i++)
        {
        	if(vis[i])
        		continue;
        	int cnt=0;
        	while(!vis[i])
        	{
        		vis[i]=1;
        		i=nums[i];
        		cnt++;
        	}
        	longest_length=max(longest_length,cnt);
        }
        return longest_length;
    }
};