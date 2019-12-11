class Solution {
public:
    // Solution 1: Space(O(n)), Time(O(1))
    // int numberOfSubarrays(vector<int>& nums, int k) 
    // {
    //     unordered_map<int,int>mp;
    //     mp[0]=1;
    //     int cnt=0,ans=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         cnt+=nums[i]%2;
    //         ans+=mp[cnt-k];
    //         mp[cnt]++;
    //     }
    //     return ans;
    // }
    
    // Solution 2: Space(O(1)), Time(O(n))
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int start1=0,odd_c1=0,odd_c2=0,start2=0,end=0,ans=0;
        while(end<nums.size())
        {
            if(nums[end]%2==1)
            {
                odd_c1++;
                odd_c2++;
            }
            while(odd_c1>k)
            {
                odd_c1-=nums[start1]%2;
                start1++;
            }
            while(odd_c2>=k)
            {
                odd_c2-=nums[start2]%2;
                start2++;
            }
            ans+=start2-start1;
            end++;
        }
        return ans;
    }
};