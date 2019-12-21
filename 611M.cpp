class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int k=i+1;
            for(int j=i+1;j<nums.size();j++)
            {
                while(k<nums.size() && nums[k]<nums[i]+nums[j])
                    k++;
                k--;
                if(k>j)
                    ans+=(k-j);
            }
        }
        return ans;
    }
};