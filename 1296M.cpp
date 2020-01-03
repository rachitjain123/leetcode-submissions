class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]])
            {
                for(int j=nums[i]+1;j<nums[i]+k;j++)
                {
                    if(mp.find(j)==mp.end() || mp[j]<mp[nums[i]])
                        return false;
                    mp[j]=mp[j]-mp[nums[i]];
                }
                mp[nums[i]]=0;
            }
        }
        return true;
    }
};
