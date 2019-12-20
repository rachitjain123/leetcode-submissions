class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(n==2)
        {
            if(nums[0]==nums[1])
                return 1;
            return 0;
        }
        int min_moves;
        int moves1=0,moves2=0;
        for(int i=1;i<n;i+=2)
        {
            int li=0,ri=0;
            if(i+1>=n)
                ri=INT_MAX;
            else
                ri=nums[i+1];
            if(i-1<0)
                li=INT_MAX;
            else
                li=nums[i-1];
            if(nums[i]>min(ri,li)-1)
                moves1+=nums[i]-min(li,ri)+1;
        }
        for(int i=1;i<n;i+=2)
        {
            int li=0,ri=0;
            if(i+1<n)
            {
                if(nums[i+1]>=nums[i])
                {
                    moves2+=nums[i+1]-nums[i]+1;
                    nums[i+1]=nums[i]-1;
                }
            }
            if(i-1>=0)
            {
                if(nums[i-1]>=nums[i])
                {
                    moves2+=nums[i-1]-nums[i]+1;
                    nums[i-1]=nums[i]-1;
                }
            }
        }
        min_moves=min(moves1,moves2);
        return min_moves;
    }
};