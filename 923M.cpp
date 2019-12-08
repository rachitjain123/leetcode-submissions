class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        long long int ans=0;
        long long int mod=(long long int)(1e9+7);
		for(int i=0;i<nums.size();i++)
		{
			int j=i+1,k=nums.size()-1;
			while(j<k)
			{
				long long int diff=(long long int)(nums[i]+nums[j]+nums[k]-target);
				if(diff==0)
                {
                    if(nums[j]!=nums[k])
                    {
                        long long int left=1,right=1;
                        while(j+1<k && nums[j]==nums[j+1])
                        {
                            j++;
                            left++;
                        }
                        while(k-1>j && nums[k]==nums[k-1])
                        {
                            k--;
                            right++;
                        }
                        ans=(ans%mod + (left%mod*right%mod)%mod)%mod;
                        j++;
                        k--;
                    }
                    else
                    {
                        long long int val= (k-j+1)*(k-j)/2;
                        ans=(ans%mod+val%mod)%mod;
                        break;
                    }
                }
				else if(diff<0)
					j++;
				else
					k--;
			}
		}
		return ans;    
    }
};