class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		sort(nums.begin(),nums.end());
		vector<vector<int>>perm;
		for(int i=0;i<nums.size();i++)
		{
			if(i>0 && nums[i]==nums[i-1])
				continue;
			for(int j=i+1;j<nums.size();j++)
			{
				if(nums[j]==nums[j-1] && j>i+1)
					continue;
				int k=j+1,l=nums.size()-1;
				while(k<l)
				{
					long long int sum=(long long int)(nums[i]+nums[j]+nums[k]+nums[l]);
					if(sum==target)
					{	
						vector<int>comb;
						comb.push_back(nums[i]);
						comb.push_back(nums[j]);
						comb.push_back(nums[k]);
						comb.push_back(nums[l]);
						perm.push_back(comb);
						k++;
						l--;
						while(k<l && nums[k]==nums[k-1])
							k++;
						while(k<l && nums[l]==nums[l+1])
							l--;

					}
					else if(sum>target)
						l--;
					else
						k++;
				}
			}
		}
		return perm;
	}
};