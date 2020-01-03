    class Solution {
    public:
        int numRabbits(vector<int>& nums) {
            int rabbits=0;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++)
            {
                int j=i;
                while(j<nums.size() && nums[i]==nums[j])
                    j++;
                if(j-i<=nums[i]+1)
                    rabbits+=nums[i]+1;
                else
                {
                    int num_cnt=j-i;
                    rabbits+=(nums[i]+1)*(num_cnt/(nums[i]+1));
                    if(num_cnt%(nums[i]+1))
                        rabbits+=nums[i]+1;
                }
                i=j-1;
            }
            return rabbits;
        }
    };