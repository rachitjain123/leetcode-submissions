class Solution {
    int cal(int divisor,vector<int>&nums)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]/divisor;
            if(nums[i]%divisor!=0)
                sum++;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end()),ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(cal(mid, nums)<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};