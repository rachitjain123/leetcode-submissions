class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		sort(nums.begin(),nums.end());
		long long int min_abs_diff=(long long int)1e10;
        long long int sum_tot_integers=0;
		for(int i=0;i<nums.size();i++)
		{
			int j=i+1,k=nums.size()-1;
			while(j<k)
			{
				long long int diff=(long long int)(nums[i]+nums[j]+nums[k]-target);
				if(abs(diff)<min_abs_diff)
                {
					min_abs_diff=abs(diff);
                    sum_tot_integers=(long long int)(nums[i]+nums[j]+nums[k]);
                }
				if(diff==0)
					break;
				else if(diff<0)
					j++;
				else
					k--;
			}
		}
		return sum_tot_integers;
	}
};