class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!nums[i])
                nums[i]=-1;
        }
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==0)
                ans=max(ans,i+1);
            if(mp[sum]==0)
                mp[sum]=i+1;
            else
                ans=max(ans,i+1-mp[sum]);
        }
        return ans;
    }
};