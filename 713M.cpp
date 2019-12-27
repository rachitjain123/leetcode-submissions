class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int prod=1,ans=0;
        int i=0,j=0;
        while(j<nums.size())
        {
            prod=prod*nums[j];
            while(prod>=k && j>=i)
            {
                prod=prod/nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};