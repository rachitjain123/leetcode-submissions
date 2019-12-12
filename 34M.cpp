class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int first_pos=-1,last_pos=high+1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
            {
                first_pos=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        vector<int>ans;
        if(first_pos==-1||nums[first_pos]!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
            {
                last_pos=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        last_pos--;
        ans.push_back(first_pos);
        ans.push_back(last_pos);
        return ans;
    }
};